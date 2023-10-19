//
// History.h
//
#ifndef _HISTORY_H_
#define _HISTORY_H_

template<typename T>
class CHistory
{
public:
	CHistory(size_t capacity);
	~CHistory();

private:
	std::vector<T> m_history;
};

#endif