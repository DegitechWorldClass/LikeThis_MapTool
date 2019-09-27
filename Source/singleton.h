#pragma once
template <typename T>
class singleton
{
public:
	singleton() {}
	virtual ~singleton() {}
private:
	static T * instance;
public:
	static T * Instance()
	{
		if (!instance)
			instance = new T();
		return instance;
	}
	static void ReleaseInstance()
	{
		delete instance;
		instance = nullptr;
	}
};
template <class T>
T* singleton<T>::instance = nullptr;