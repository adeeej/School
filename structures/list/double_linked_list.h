#pragma once

#include "linked_list.h"

namespace structures
{
    // implementacne tipy: 
    //  - namiesto triedy List<T> mozete v triede DoubleLinkedList<T> 
    //    zdedit jednostranne zretazeny zoznam (LinkedList<T>).
    //    ak tak urobite, mozete mnoho metod odstranit a prekryt iba tie, 
    //    ktore maju z pohladu obojsmerne zretazeneho zoznamu vyznam a
    //    zvysok nechat na predka.
    //  - nezabudnite si vytvorit triedu pre prvok obojstranne zretazeneho zoznamu.
    //    opat tento prvok mozete zdedit z prvku jednostranne zretazeneho zoznamu.
    //  - ak vyuzijete dedicnost, budete moct vyuzit predkove iteratory, 
    //    takze ich nebudete musiet implementovat.

    /// <summary> Prvok obojstranne zretazeneho zoznamu. </summary>
    /// <typeparam name = "T"> Typ dat ukladanych v prvku. </typepram>
    template<typename T>
    class DoubleLinkedListItem : public LinkedListItem<T>
    {
    public:
        /// <summary> Konstruktor. </summary>
        /// <param name = "data"> Data, ktore uchovava. </param>
        DoubleLinkedListItem(T data);

        /// <summary> Kopirovaci konstruktor. </summary>
        /// <param name = "other"> Prvok obojstranne zretazeneho zoznamu, z ktoreho sa prevezmu vlastnosti.. </param>
        DoubleLinkedListItem(DoubleLinkedListItem<T>& other);

        /// <summary> Destruktor. </summary>
        ~DoubleLinkedListItem();

        /// <summary> Getter predchadzajuceho prvku zretazeneho zoznamu. </summary>
        /// <returns> Predchadzajuci prvok zretazeneho zoznamu. </returns>
        DoubleLinkedListItem<T>* getPrevious();

        /// <summary> Setter predchadzajuceho prvku zretazeneho zoznamu. </summary>
        /// <param name´= "next"> Novy predchadzajuci prvok zretazeneho zoznamu. </param>
        void setPrevious(DoubleLinkedListItem<T>* previous);

    private:
        /// <summary> Predchadzajuci prvok zretazeneho zoznamu. </summary>
        DoubleLinkedListItem<T>* previous_;
    };

    /// <summary> Obojstranne zretazeny zoznam. </summary>
    /// <typeparam name = "T"> Typ dat ukladanych v zozname. </typepram>
    template<typename T>
    class DoubleLinkedList : public LinkedList<T>
    {
    public:
        /// <summary> Konstruktor. </summary>
        DoubleLinkedList();

        /// <summary> Kopirovaci konstruktor. </summary>
        /// <param name = "other"> DoubleLinkedList, z ktoreho sa prevezmu vlastnosti. </param>
        DoubleLinkedList(DoubleLinkedList<T>& other);

        /// <summary> Destruktor. </summary>
        ~DoubleLinkedList();

        /// <summary> Vrati pocet prvkov v zozname. </summary>
        /// <returns> Pocet prvkov v zozname. </returns>
        //size_t size() override;

        /// <summary> Priradenie struktury. </summary>
        /// <param name = "other"> Struktura, z ktorej ma prebrat vlastnosti. </param>
        /// <returns> Adresa, na ktorej sa struktura nachadza. </returns>
        //Structure& assign(Structure& other) override;

        /// <summary> Porovnanie struktur. </summary>
        /// <param name="other">Struktura, s ktorou sa ma tato struktura porovnat. </param>
        /// <returns>True ak su struktury zhodne typom aj obsahom. </returns>
        bool equals(Structure& other) override;

        /// <summary> Vrati adresou prvok na indexe. </summary>
        /// <param name = "index"> Index prvku. </param>
        /// <returns> Adresa prvku na danom indexe. </returns>
        /// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>
        //T& at(int index) override;

        /// <summary> Prida prvok do zoznamu. </summary>
        /// <param name = "data"> Pridavany prvok. </param>
        void add(const T& data) override;

        /// <summary> Vlozi prvok do zoznamu na dany index. </summary>
        /// <param name = "data"> Pridavany prvok. </param>
        /// <param name = "index"> Index prvku. </param>
        /// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>
        /// <remarks> Ak je ako index zadana hodnota poctu prvkov (teda prvy neplatny index), metoda insert sa sprava ako metoda add. </remarks>
        void insert(const T& data, int index) override;

        /// <summary> Odstrani prvy vyskyt prvku zo zoznamu. </summary>
        /// <param name = "data"> Odstranovany prvok. </param>
        /// <returns> true, ak sa podarilo prvok zo zoznamu odobrat, false inak. </returns>
        //bool tryRemove(const T& data) override;

        /// <summary> Odstrani zo zoznamu prvok na danom indexe. </summary>
        /// <param name = "index"> Index prvku. </param>
        /// <returns> Odstraneny prvok. </returns>
        /// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>
        T removeAt(int index) override;

        /// <summary> Vrati index prveho vyskytu prvku v zozname. </summary>
        /// <param name = "data"> Prvok, ktoreho index sa hlada. </param>
        /// <returns> Index prveho vyskytu prvku v zozname, ak sa prvok v zozname nenachadza, vrati -1. </returns>
        //int getIndexOf(const T& data) override;

        /// <summary> Vymaze zoznam. </summary>
        //void clear() override;

    private:
        DoubleLinkedListItem<T>* getItemAtIndex(int index) override;
    };

    template<typename T>
    inline DoubleLinkedList<T>::DoubleLinkedList() :
        LinkedList<T>()
    {
    }

    template<typename T>
    inline DoubleLinkedList<T>::DoubleLinkedList(DoubleLinkedList<T>& other)
    {
        assign(other);
    }

    template<typename T>
    inline DoubleLinkedList<T>::~DoubleLinkedList()
    {
        clear();
    }

    template<typename T>
    inline bool DoubleLinkedList<T>::equals(Structure& other)
    {
        if (size_ != other.size())
            return false;

        if (this == &other)
            return true;

        DoubleLinkedList<T>* otherList = dynamic_cast<DoubleLinkedList<T>*>(&other);
        if (otherList == nullptr)
            return false;

        LinkedListItem<T>* item = first_;
        LinkedListItem<T>* otherItem = otherList->first_;

        while (item != nullptr)
        {
            if (item->accessData() != otherItem->accessData())
            {
                return false;
            }
            item = item->getNext();
            otherItem = otherItem->getNext();
        }
        return true;
    }

    template<typename T>
    inline void DoubleLinkedList<T>::add(const T& data)
    {
        DoubleLinkedListItem<T>* newDLLI = new DoubleLinkedListItem<T>(data);
        if (size_ == 0)
        {
            first_ = newDLLI;
        }
        else
        {
            last_->setNext(newDLLI);
            newDLLI->setPrevious(dynamic_cast<DoubleLinkedListItem<T>*>(last_));
        }
        last_ = newDLLI;
        size_++;
    }

    template<typename T>
    inline void DoubleLinkedList<T>::insert(const T& data, int index)
    {
        if (index == size_)
        {
            add(data);
        }
        else
        {
            Utils::rangeCheckExcept(index, size_, "Invalid index");
            DoubleLinkedListItem<T>* newDLLI = new DoubleLinkedListItem<T>(data);

            if (index == 0)
            {
                newDLLI->setNext(first_);
                dynamic_cast<DoubleLinkedListItem<T>*>(first_)->setPrevious(newDLLI);
                first_ = newDLLI;
            }
            else
            {
                DoubleLinkedListItem<T>* pred = getItemAtIndex(index);
                pred->getPrevious()->setNext(newDLLI);
                newDLLI->setPrevious(pred->getPrevious());
                newDLLI->setNext(pred);
                pred->setPrevious(newDLLI);
            }
            size_++;
        }
    }

    template<typename T>
    inline T DoubleLinkedList<T>::removeAt(int index)
    {
        Utils::rangeCheckExcept(index, size_, "Invalid index");
        DoubleLinkedListItem<T>* delItem;
        if (index == 0)
        {
            delItem = dynamic_cast<DoubleLinkedListItem<T>*>(first_);
            first_ = first_->getNext();
            if (first_ != nullptr)
            {
                dynamic_cast<DoubleLinkedListItem<T>*>(first_)->setPrevious(nullptr);
            }
           
            if (delItem == last_)
            {
                last_ = nullptr;
            }
        }
        else
        {
            delItem = getItemAtIndex(index);
            delItem->getPrevious()->setNext(delItem->getNext());
            if (delItem == last_)
            {
                last_ = delItem->getPrevious();
            }
            else
            {
                dynamic_cast<DoubleLinkedListItem<T>*>(delItem->getNext())->setPrevious(delItem->getPrevious());
            }
        }

        T result = delItem->accessData();
        delete delItem;
        size_--;
        return result;
    }

    template<typename T>
    inline DoubleLinkedListItem<T>* DoubleLinkedList<T>::getItemAtIndex(int index)
    {
        if (index == size_ - 1)
        {
            return dynamic_cast<DoubleLinkedListItem<T>*>(last_);
        }

        DoubleLinkedListItem<T>* current;
        if (index > (size_ - 1) / 2)
        {
        //idem od konca
            current = dynamic_cast<DoubleLinkedListItem<T>*>(last_);
            for (size_t i = size_ - 1; i > index; i--)
            {
                current = current->getPrevious();
            }
        }
        else
        {
        //idem od zaciatku
            current = dynamic_cast<DoubleLinkedListItem<T>*>(first_);
            for (size_t i = 0; i < index; i++)
            {
                current = dynamic_cast<DoubleLinkedListItem<T>*>(current->getNext());
            }
        }

        return current;
    }

    template<typename T>
    inline DoubleLinkedListItem<T>::DoubleLinkedListItem(T data) :
        LinkedListItem<T>(data),
        previous_(nullptr)
    {
    }

    template<typename T>
    inline DoubleLinkedListItem<T>::DoubleLinkedListItem(DoubleLinkedListItem<T>& other) :
        LinkedListItem<T>(other),
        previous_(other.previos)
    {
    }

    template<typename T>
    inline DoubleLinkedListItem<T>::~DoubleLinkedListItem()
    {
        LinkedListItem<T>::~LinkedListItem();
        previous_ = nullptr;
    }

    template<typename T>
    inline DoubleLinkedListItem<T>* DoubleLinkedListItem<T>::getPrevious()
    {
        return previous_;
    }

    template<typename T>
    inline void DoubleLinkedListItem<T>::setPrevious(DoubleLinkedListItem<T>* previous)
    {
        previous_ = previous;
    }
}