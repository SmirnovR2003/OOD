#pragma once

#include <set>
#include <string>
#include <functional>
#include<boost/signals2/signal.hpp>
namespace signals = boost::signals2;

template <typename T>
class IObserver;
/*
Шаблонный интерфейс IObservable. Позволяет подписаться и отписаться на оповещения, а также
инициировать рассылку уведомлений зарегистрированным наблюдателям.
*/
template <typename T>
class IObservable
{
public:
	using UpdateSignal = signals::signal<void(T data)>;
	virtual ~IObservable() = default;
	virtual void NotifyObservers() = 0;
	virtual void RemoveObserver(IObserver<T>& observer) = 0;
	virtual signals::connection RegisterObserver(IObserver<T>& observer) = 0;
};

// Реализация интерфейса IObservable
template <class T>
class CObservable : public IObservable<T>
{
public:
	//передавать ссылку на самого себя
	typedef IObserver<T> ObserverType;

	signals::connection RegisterObserver(ObserverType& observer) override
	{
		observer.AddObservable(this);
		return m_sigObservers.connect(bind(&ObserverType::Update, &observer, ph::_1));
	}
	void NotifyObservers() override
	{
		T data = GetChangedData();
		m_sigObservers(data);
	}

	void RemoveObserver(ObserverType & observer) override
	{
		//m_observers.erase(&observer);
		//m_sigObservers.disconnect(observer);
	}
protected:
	// Классы-наследники должны перегрузить данный метод, 
	// в котором возвращать информацию об изменениях в объекте
	virtual T GetChangedData()const = 0;

private:
	UpdateSignal m_sigObservers;
	std::set<IObservable *> m_observers;
};

/*
Шаблонный интерфейс IObserver. Его должен реализовывать класс,
желающий получать уведомления от соответствующего IObservable
Параметром шаблона является тип аргумента,
передаваемого Наблюдателю в метод Update
*/
template <typename T>
class IObserver
{
public:
	virtual void Update(T const& data) = 0;
	virtual void AddObservable(CObservable<T>* const observable) = 0;
	virtual ~IObserver() = default;
};