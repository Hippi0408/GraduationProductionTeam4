#include "history.h"

template<typename T>
CHistory<T>::CHistory(size_t capacity)
{
	m_history.reserve(capacity);
}

template<typename T>
CHistory<T>::~CHistory()
{
}