#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <vector>
# include <deque>
# include <sys/time.h>

class PmergeMe {

	private:
		std::vector<int> _v;
		std::deque<int> _d;
		bool _valid;

	public:

		PmergeMe();
		PmergeMe(char ** argv);
		PmergeMe(PmergeMe const & src);
		virtual ~PmergeMe();

		PmergeMe & operator=(PmergeMe const & rhs);

		void sort();
	
	private:

		bool _parse(char ** argv);
		bool _isNumber(std::string str);
		
		template <typename T>
		void _merge(T &arr, size_t start, size_t middle, size_t end)
		{
			size_t left_size = middle - start + 1;
			size_t right_size = end - middle;
			T left_list(left_size+1);
			T right_list(right_size+1);

			for (size_t i = 0; i < left_size; i++)
				left_list[i] = arr[start+i];
			for (size_t j = 0; j < right_size; j++)
				right_list[j] = arr[middle+j+1];

			left_list[left_size] = INT_MAX;
			right_list[right_size] = INT_MAX;
			size_t i = 0, j = 0;
			for (size_t k = start; k <= end; k++)
			{
				if (left_list[i] <= right_list[j])
				{
					arr[k] = left_list[i];
					i++;
				}
				else
				{
					arr[k] = right_list[j];
					j++;
				}
			}
		}

		template <typename T>
		void _insertion(T &arr, size_t start, size_t end)
		{
			for (size_t i = start+1; i <= end; i++)
			{
				size_t j = i;
				while (j > start && arr[j] < arr[j-1])
				{
					std::swap(arr[j], arr[j-1]);
					j--;
				}
			}
		}

		template <typename T>
		void _merge_insert_sort(T &arr, size_t start, size_t end)
		{
			if (end - start <= 10)
				_insertion(arr, start, end);
			else
			{
				int middle = (start + end) / 2;
				_merge_insert_sort(arr, start, middle);
				_merge_insert_sort(arr, middle+1, end);
				_merge(arr, start, middle, end);
			}
		}

};


#endif
