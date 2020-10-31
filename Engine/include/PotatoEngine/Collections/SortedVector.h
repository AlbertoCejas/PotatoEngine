#pragma once

#include <vector>
#include <algorithm>

namespace potato
{

	template <typename T, typename Predicate = std::less<T>>
	class SortedVector
	{
		public:

			using Iterator = typename std::vector<T>::iterator;
			using ConstIterator = typename std::vector<T>::const_iterator;

			SortedVector() = default;
			explicit SortedVector(const Predicate& comparator);
			explicit SortedVector(size_t capacity);
			explicit SortedVector(size_t capacity, const Predicate& comparator);
			~SortedVector() = default;
			SortedVector(const SortedVector& other);
			SortedVector(SortedVector&& other);
			SortedVector& operator=(const SortedVector& other);
			SortedVector& operator=(SortedVector&& other);
			SortedVector& operator=(std::initializer_list<T> list);
			
			void reserve(size_t capacity);

			void clear();

			void push(T& element);
			template <class... Args>
			void push(Args&&... elements);
			void emplace(T& element);
			template <class... Args>
			void emplace(Args&&... elements);

			Iterator erase(const T& element);
			Iterator erase(Iterator position);
			Iterator erase(Iterator first, Iterator last);

			bool empty() const;
			size_t size() const;
			T& at(size_t index) const;
			T& operator[](size_t pos);
			const T& operator[](size_t pos) const;

			Iterator begin();
			ConstIterator begin() const;
			Iterator end();
			ConstIterator end() const;

		private:

			std::vector<T> m_elements{};
			Predicate m_comparator{};
	};

	template <typename T, typename Predicate>
	SortedVector<T, Predicate>::SortedVector(const Predicate& comparator) :
		m_comparator(comparator) {}

	template <typename T, typename Predicate>
	SortedVector<T, Predicate>::SortedVector(size_t capacity) :
		m_elements(capacity) {}

	template <typename T, typename Predicate>
	SortedVector<T, Predicate>::SortedVector(size_t capacity, const Predicate& comparator) :
		m_elements(capacity),
		m_comparator(comparator) {}

	template <typename T, typename Predicate>
	SortedVector<T, Predicate>::SortedVector(const SortedVector& other) :
		m_elements(other.m_elements),
		m_comparator(other.m_comparator) {}

	template <typename T, typename Predicate>
	SortedVector<T, Predicate>::SortedVector(SortedVector&& other) :
		m_elements(std::move(other.m_elements)),
		m_comparator(std::move(other.m_comparator)) {}

	template <typename T, typename Predicate>
	SortedVector<T, Predicate>& SortedVector<T, Predicate>::operator=(const SortedVector& other)
	{
		m_elements = other.m_elements;
		m_comparator = other.m_comparator;
	}

	template <typename T, typename Predicate>
	SortedVector<T, Predicate>& SortedVector<T, Predicate>::operator=(std::initializer_list<T> list)
	{
		m_elements = list;
		std::sort_heap(m_elements.begin(), m_elements.end(), m_comparator);
	}

	template <typename T, typename Predicate>
	SortedVector<T, Predicate>& SortedVector<T, Predicate>::operator=(SortedVector&& other)
	{
		m_elements = std::move(other.m_elements);
		m_comparator = std::move(other.m_comparator);
	}

	template <typename T, typename Predicate>
	void SortedVector<T, Predicate>::reserve(size_t capacity)
	{
		m_elements.reserve(capacity);
	}

	template <typename T, typename Predicate>
	void SortedVector<T, Predicate>::clear()
	{
		m_elements.clear();
	}

	template <typename T, typename Predicate>
	void SortedVector<T, Predicate>::push(T& element)
	{
		m_elements.push_back(element);
		std::push_heap(m_elements.begin(), m_elements.end(), m_comparator);
	}

	template <typename T, typename Predicate>
	template <class... Args>
	void SortedVector<T, Predicate>::push(Args&&... elements)
	{
		m_elements.push_back(std::forward<Args>(elements)...);
		std::sort_heap(m_elements.begin(), m_elements.end(), m_comparator);
	}

	template <typename T, typename Predicate>
	void SortedVector<T, Predicate>::emplace(T& element)
	{
		m_elements.push.emplace_back(element);
		std::push_heap(m_elements.begin(), m_elements.end(), m_comparator);
	}

	template <typename T, typename Predicate>
	template <class... Args>
	void SortedVector<T, Predicate>::emplace(Args&&... elements)
	{
		m_elements.emplace_back(std::forward<Args>(elements)...);
		std::sort_heap(m_elements.begin(), m_elements.end(), m_comparator);
	}

	template <typename T, typename Predicate>
	typename SortedVector<T, Predicate>::Iterator SortedVector<T, Predicate>::erase(const T& element)
	{
		auto it = std::find(m_elements.begin(), m_elements.end(), element);
		if (it != m_elements.end())
		{
			return erase(it);
		}
		else
		{
			return m_elements.end();
		}
	}

	template <typename T, typename Predicate>
	typename SortedVector<T, Predicate>::Iterator SortedVector<T, Predicate>::erase(Iterator position)
	{
		const size_t positionIndex = position - m_elements.begin();
		Iterator it = m_elements.erase(position);
		if (positionIndex == m_elements.size())
		{
			std::pop_heap(m_elements.begin(), m_elements.end(), m_comparator);
		}
		else
		{
			std::sort_heap(m_elements.begin(), m_elements.end(), m_comparator);
		}
		return it;
	}
	template <typename T, typename Predicate>
	typename SortedVector<T, Predicate>::Iterator SortedVector<T, Predicate>::erase(Iterator first, Iterator last)
	{
		Iterator it = m_elements.erase(first, last);
		std::sort_heap(m_elements.begin(), m_elements.end(), m_comparator);
		return it;
	}

	template <typename T, typename Predicate>
	inline bool SortedVector<T, Predicate>::empty() const
	{
		return m_elements.empty();
	}

	template <typename T, typename Predicate>
	inline size_t SortedVector<T, Predicate>::size() const
	{
		return m_elements.size();
	}

	template <typename T, typename Predicate>
	inline T& SortedVector<T, Predicate>::at(size_t index) const
	{
		return m_elements.at(index);
	}


	template <typename T, typename Predicate>
	inline T& SortedVector<T, Predicate>::operator[](size_t pos)
	{
		return m_elements[pos];
	}

	template <typename T, typename Predicate>
	inline const T& SortedVector<T, Predicate>::operator[](size_t pos) const
	{
		return m_elements[pos];
	}

	template <typename T, typename Predicate>
	inline typename SortedVector<T, Predicate>::Iterator SortedVector<T, Predicate>::begin()
	{
		return m_elements.begin();
	}

	template <typename T, typename Predicate>
	inline typename SortedVector<T, Predicate>::ConstIterator SortedVector<T, Predicate>::begin() const
	{
		return m_elements.begin();
	}

	template <typename T, typename Predicate>
	inline typename SortedVector<T, Predicate>::Iterator SortedVector<T, Predicate>::end()
	{
		return m_elements.end();
	}

	template <typename T, typename Predicate>
	inline typename SortedVector<T, Predicate>::ConstIterator SortedVector<T, Predicate>::end() const
	{
		return m_elements.end();
	}
}