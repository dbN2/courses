#ifndef SET_H
#define SET_H

namespace myset
{
	template <class T>
	class Set
	{
		private:
			T *items;
			int num_items;
		public:
			Set();
			~Set();
			Set(const Set<T> & other);
			void operator =(const Set<T>& right_side);
			void add(T item);
			void remove(T item);
			int size() const;
			bool contains(T item);
			T *toArray() const;
	};

}

#endif

