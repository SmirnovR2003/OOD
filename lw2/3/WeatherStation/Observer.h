#pragma once

#include <set>
#include <map>
#include <list>
#include <vector>
#include <functional>
#include <algorithm>
#include <sstream>
#include <algorithm>
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
	virtual void Update(T const& data, std::ostringstream& os) = 0;
	virtual ~IObserver() = default;
};

/*
Шаблонный интерфейс IObservable. Позволяет подписаться и отписаться на оповещения, а также
инициировать рассылку уведомлений зарегистрированным наблюдателям.
*/
template <typename T>
class IObservable
{
public:
	virtual ~IObservable() = default;
	virtual void RegisterObserver(IObserver<T> & observer, int priority) = 0;
	virtual void NotifyObservers(std::ostringstream& os) = 0;
	virtual void RemoveObserver(IObserver<T> & observer) = 0;
};

// Реализация интерфейса IObservable
template <class T>
class CObservable : public IObservable<T>
{
public:
	typedef IObserver<T> ObserverType;

	void RegisterObserver(ObserverType & observer, int priority) override
	{
		m_observers.insert({ priority , &observer });
	}

	void NotifyObservers(std::ostringstream& os) override
	{
		T data = GetChangedData();
		for (auto iter = m_observers.rbegin(); iter != m_observers.rend();++iter)
		{
			iter->second->Update(data,os);
		}
	}

	void RemoveObserver(ObserverType & observer) override
	{
		//find_if
		for (auto iter = m_observers.begin(); iter != m_observers.end();++iter)
		{
			if (iter->second == &observer)
			{
				iter = m_observers.erase(iter);
				return;
			}
		}
	}

protected:
	// Классы-наследники должны перегрузить данный метод, 
	// в котором возвращать информацию об изменениях в объекте
	virtual T GetChangedData()const = 0;

private:
	std::multimap< int, ObserverType* > m_observers;
};
