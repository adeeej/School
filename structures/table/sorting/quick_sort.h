#pragma once

#include "sort.h"
#include "../unsorted_sequence_table.h"
#include "../../../kriterium.h"

namespace structures
{
	/// <summary> Triedenie Quick sort. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T, typename V>
	class QuickSort
	{
	public:
		/// <summary> Utriedi tabulku triedenim Quick sort. </summary>
		/// <param name = "table"> NonortedSequenceTable, ktoru ma utriedit. </param>
		QuickSort(Kriterium<T, V>* kriterium) { kriterium_ = kriterium; }
		void sort(UnsortedSequenceTable<K, T>& table, bool smer);
		void quick(int min, int max, UnsortedSequenceTable<K, T>& table, bool smer);

	private:
		//void quick(int min, int max, UnsortedSequenceTable<K, T>& table);
		Kriterium<T, V>* kriterium_;
	};

	template<typename K, typename T, typename V>
	inline void QuickSort<K, T, V>::quick(int min, int max, UnsortedSequenceTable<K, T>& table, bool smer)
	{
		T pivot = table.getItemAtIndex((min + max) / 2).accessData();
		int lavy = min;
		int pravy = max;

		do
		{
			while (smer ? kriterium_->evaluate(table.getItemAtIndex(lavy).accessData()) < kriterium_->evaluate(pivot) : kriterium_->evaluate(table.getItemAtIndex(lavy).accessData()) > kriterium_->evaluate(pivot))
			{
				lavy++;
			}
			while (smer ? kriterium_->evaluate(table.getItemAtIndex(pravy).accessData()) > kriterium_->evaluate(pivot) : kriterium_->evaluate(table.getItemAtIndex(pravy).accessData()) < kriterium_->evaluate(pivot))
			{
				pravy--;
			}
			if (lavy <= pravy)
			{
				table.swap(lavy, pravy);
				lavy++;
				pravy--;
			}
		} while (lavy <= pravy);

		if (min < pravy)
		{
			quick(min, pravy, table, smer);
		}
		if (lavy < max)
		{
			quick(lavy, max, table, smer);
		}
	}

	template<typename K, typename T, typename V>
	inline void QuickSort<K, T, V>::sort(UnsortedSequenceTable<K, T>& table, bool smer)
	{
		quick(0, table.size() - 1, table, smer);
	}
}