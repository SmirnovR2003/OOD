#pragma once

#include <vector>
#include <string>
#include <functional>
#include <map>



/*
Шаблонный интерфейс IObserver. Его должен реализовывать класс, 
желающий получать уведомления от соответствующего IObservable
Параметром шаблона является тип аргумента,
передаваемого Наблюдателю в метод Update
*/
template <class Type, class T>
class IObserver
{
public:
	virtual void Update(Type type, T const& data) = 0;
	virtual ~IObserver() = default;
};

/*
Шаблонный интерфейс IObservable. Позволяет подписаться и отписаться на оповещения, а также
инициировать рассылку уведомлений зарегистрированным наблюдателям.
*/
template <class Type, class T>
class IObservable
{
public:
	virtual ~IObservable() = default;
	virtual void RegisterObserver(Type type, IObserver<Type, T> & observer) = 0;
	virtual void NotifyObservers(Type type) = 0;
	virtual void RemoveObserver(Type type, IObserver<Type, T> & observer) = 0;
};

// Реализация интерфейса IObservable
template <class Type, class T>
class CObservable : public IObservable<Type, T>
{
public:
	CObservable(std::string& name):m_name(name) {}
	typedef IObserver<Type, T> ObserverType;

	void RegisterObserver(Type type, ObserverType & observer) override
	{
		m_observers.insert({ type, &observer });
	}

	void NotifyObservers(Type type) override
	{
		T data = GetChangedData();
		auto its = m_observers.equal_range(type);
		for (auto it = its.first; it != its.second; ++it)
		{
			it->second->Update(type, data);
		}
	}

	//добавить приоритеты
	void RemoveObserver(Type type, ObserverType & observer) override
	{
		auto its = m_observers.equal_range(type);
		for (auto it = its.first; it != its.second; ++it)
		{
			if (it->second == &observer) 
			{
				m_observers.erase(it);
				break;
			}
		}
	}

	std::string GetSensorName()const 
	{
		return m_name;
	}

protected:
	// Классы-наследники должны перегрузить данный метод, 
	// в котором возвращать информацию об изменениях в объекте
	virtual T GetChangedData()const = 0;

private:
	std::string m_name;
	std::multimap<Type, ObserverType *> m_observers;
};
