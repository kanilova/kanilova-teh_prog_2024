#include <iostream>
using namespace std;

class element
{
    public:
        double value;
        element *next; // Указатель на следующий элемент в списке

        element(double v = 0)
	    {
            this->value = v;
            next = NULL;
        }

        // Метод для вывода значения элемента на экран
        void print()
	    {
            cout << "value: " << value;
        }
};



class list
{
    private:
        element *head;//указатель на начало списка

    public:
    //конструктор создает пустой указатель
        list()
	    {
            head = NULL;
        }

        //добавить в конец



        void push_back(double value)
	    {
            element *newElem = new element(value);
            if (head == NULL)
		    {
                head = newElem;
                return;
            }
            element *temp = head;
            while (temp->next != NULL)
		    {
                temp = temp->next;
            }
            temp->next = newElem;
        }

        //добавить в начало

        void push_front(double value)
	    {
            element *newElem = new element(value);
            newElem->next = head;
            head = newElem;
        }


        //удалить последний

        void pop_back()
	    {
            if (head == NULL)
		    {
                cout << "List too short" << endl;
                return;
            }
            if (head->next == NULL)
		    {
                delete head;
                head = NULL;
                return;
            }

            element *temp = head;
            while (temp->next->next != NULL)
		    {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }

        //удалить первый

        void pop_front()
	    {
            if (head == NULL)
	    	{
               cout << "List too short" << endl;
                return;
            }
            element *temp = head;
            head = head->next;
            delete temp;
        }

		//удалить по индексу

	    void erase(int index)
	    {
    	    if (index > size())
		    {
       		    cout << "List too short" << endl;
        	    return;
    	    }
        if (index == 1)
	    {
            head = head->next;
            return;
        }

        element *temp = head;
        int count = 1;
        while (temp != NULL && count < index - 1)
	    {
            temp = temp->next;
            count++;
        }
        if (temp != NULL && temp->next != NULL)
        {
            temp->next = temp->next->next;
        }
        }

		//Служебный метод для вычисления размера списка
		//проходит от начала до конца и считает узлы
		int size()
		{
			element *temp = head;
    		int count = 0;
		    while (temp != NULL)
		    {
        		temp = temp->next;
        		count++;
    		}
    		return count;
		}

		//добавить по индексу

        void insert(int index, double value)
        {
            element *newElem = new element(value);
            if (index > (size() + 1))
            {
                cout << "List too short" << endl;
                return;
            }
            if (head == NULL || index == 1)
            {
                newElem->next = head;
                head = newElem;
                return;
            }
            element *temp = head;
            int count = 1;
            while (temp->next != NULL && count < index - 1)
            {
                temp = temp->next;
                count++;
            }
            if (temp->next != NULL || index == size() + 1)
            {
                newElem->next = temp->next;
                temp->next = newElem;
            }
        }

		//вывод списка


		void print()
		{
			element *temp = head;
    		while (temp != NULL)
    		{
        		temp->print();
        		cout << endl;
        		temp = temp->next;
    		}
    		cout << endl;
		}

		// найти по индексу


        element* find_by_index(int index)
        {
            index--;
            element *current = head;
            int count = 0;
            while (current != NULL)
            {
                if (count == index)
                {
                    return current;
                }
                current = current->next;
                count++;
            }
            return NULL; // Возвращает NULL, если индекс выходит за пределы списка
        }


        //найти по значению

        element* find_by_value(double value)
        {
            element *current = head;
            while (current != NULL)
            {
                if (current->value == value)
                {
                    return current;
                }
                current = current->next;
            }
            return NULL; // Возвращает NULL, если элемент с таким значением не найден
        }

        //обновить по индексу
        bool set_value_at_index(int index, double new_value)
        {
            index--;
            element *current = head;
            int current_index = 0;

            while (current != nullptr && current_index < index)
            {
                current = current->next;
                current_index++;
            }

            if (current != nullptr)
            {
                current->value = new_value;
                return true;
            } else
            {
                return false;
            }
        }

};


int main()
{
	list *l = new list();
	cout<<"create and filling"<< endl;
	l->push_back(2); //Добавляет элемент в конец списка
	l->push_front(4);//Добавляет элемент в начало списка
	l->print();//Вывод элементов списка
	cout<<"size: " << l->size() << endl << endl; // выводим размер списка

	l->insert(2, -1);
	l->print();//Вывод элементов списка
	l->set_value_at_index(2, -2);
	l->print();//Вывод элементов списка


	// Пример использования метода find_by_index
    int index = 2;
    element *elemAtIndex = l->find_by_index(index);
    if (elemAtIndex)
    {
        cout << "Element at index " << index << ": ";
        elemAtIndex->print();
    }
    else
    {
        cout << "No element found at index " << index << endl;
    }
    cout << endl << endl;

    // Пример использования метода find_by_value
    double value = 20;
    element *elemWithValue = l->find_by_value(value);
    if (elemWithValue)
    {
        cout << "Element with value " << value << ": ";
        elemWithValue->print();
    } else
    {
        cout << "No element found with value " << value << endl;
    }

	return 0;
}
