#include <iostream>

#define Log(x) std::cout << x << std::endl
#define wait std::cin.get()

template <class T>
class stack
{
  private:
    int top;
    int size;
    T *array;

  public:
    stack(int);
    void push(T);
    void multi_push(int, T *);
    T pop();
    T *multi_pop(int);
    bool is_empty();
    bool is_full();
    T top_element();
    void clear();
    int no_of_elements();
    void display();
};

template <class T>
stack<T>::stack(int size) : size(size)
{
    top = -1;
    array = new T[size];
}

template <class T>
void stack<T>::push(T element)
{
    if (top < (size - 1))
        array[++top] = element;
    else
        Log("overflow...");
    return;
}

template <class T>
void stack<T>::multi_push(int k, T *data)
{
    for (int i = 0; i < k; i++)
        push(data[i]);
}

template <class T>
T stack<T>::pop()
{
    if (top != (-1))
        return array[top--];
    else
        Log("stack is empty...");
}

template <class T>
T *stack<T>::multi_pop(int k)
{
    T *temp = new T[k];

    for (int i = 0; i < k; i++)
        temp[i] = pop();

    return temp;
}

template <class T>
bool stack<T>::is_empty()
{
    return (top == (-1));
}

template <class T>
bool stack<T>::is_full()
{
    return (top == (size - 1));
}

template <class T>
T stack<T>::top_element()
{
    if (top != (-1))
        return array[top];
    else
        Log("No top element stack is empty...");
}

template <class T>
void stack<T>::clear()
{
    top = -1;
    return;
}

template <class T>
int stack<T>::no_of_elements()
{
    return top + 1;
}

template <class T>
void stack<T>::display()
{
    Log("");
    for (int i = top; i > -1; i--)
        Log(array[i]);
    return;
}

void object_creator(auto type, auto element_type, int size)
{
    decltype(type) stack_obj(size);

startLabel:
    Log("==========MENU==========");
    Log("1. push");
    Log("2. pop");
    Log("3. multi push (program crashes , under construction)");
    Log("4. multi pop (program crashes , under construction)");
    Log("5. is full");
    Log("6. is empty");
    Log("7. top element");
    Log("8. total element");
    Log("9. clear");
    Log("10. Display");

    Log("Enter your choice: ");
    int choice;
    std::cin >> choice;

    switch (choice)
    {

    case 1:
    {
        Log("Enter element to be pushed : ");
        decltype(element_type) element;
        std::cin >> element;
        stack_obj.push(element);
    }
    break;

    case 2:
    {
        decltype(element_type) var;
        var = stack_obj.pop();
        Log("poped element is :: ");
        Log(var);
    }
    break;

    case 3:
    {
        Log("Enter no of element to be pushed : ");
        int count;
        decltype(element_type) arr[count];
        for (int i = 0; i < count; i++)
            std::cin >> arr[i];
        stack_obj.multi_push(count, arr);
    }
    break;

    case 4:
    {
        Log("Enter no of element to be poped : ");
        int count;
        decltype(element_type) *arr;
        arr = stack_obj.multi_pop(count);
        for (int i = 0; i < count; i++)
            Log(arr[i]);
    }
    break;

    case 5:
        stack_obj.is_full() ? Log("stack is full") : Log("stack is not full");
        break;

    case 6:
        stack_obj.is_empty() ? Log("stack is empty") : Log("stack is not empty");
        break;

    case 7:
    {
        Log("top element is ");
        Log(stack_obj.top_element());
    }
    break;

    case 8:
    {
        Log("total no of elements : ");
        Log(stack_obj.no_of_elements());
    }
    break;

    case 9:
    {
        stack_obj.clear();
        Log("cleared the stack ");
    }
    break;

    case 10:
        stack_obj.display();
        break;

    default:
        Log("Inavlid option...");
    }

    Log("\nPress 0 to exit : ");
    std::cin >> choice;

    if (choice != 0)
        goto startLabel;

    return;
}

int main()
{
    Log("Enter the size of stack : ");
    int size;
    std::cin >> size;

    Log("Enter type of data you want to enter : ");
    Log("==========MENU==========");
    Log("1. Boolean ");
    Log("2. Short ");
    Log("3. Integer ");
    Log("4. Unsigned Integer");
    Log("5. Long ");
    Log("6. Float ");
    Log("7. Double ");
    Log("8. Character ");
    Log("9. String ");
    Log("10. Object ");

    Log("Enter your choice: ");
    int type_data;
    std::cin >> type_data;

    switch (type_data)
    {
    case 1:
    {
        stack<bool> bool_obj(size);
        object_creator(bool_obj, true, size);
    }
    break;

    case 2:
    {
        stack<short> short_obj(size);
        object_creator(short_obj, (short)1, size);
    }
    break;

    case 3:
    {
        stack<int> int_obj(size);
        object_creator(int_obj, 1, size);
    }
    break;

    case 4:
    {
        stack<unsigned int> uint_obj(size);
        object_creator(uint_obj, 1U, size);
    }
    break;

    case 5:
    {
        stack<long> long_obj(size);
        object_creator(long_obj, 1l, size);
    }
    break;

    case 6:
    {
        stack<float> float_obj(size);
        object_creator(float_obj, 1.1f, size);
    }
    break;

    case 7:
    {
        stack<double> double_obj(size);
        object_creator(double_obj, 1.1, size);
    }
    break;

    case 8:
    {
        stack<char> char_obj(size);
        object_creator(char_obj, 'a', size);
    }
    break;

    default:
        Log("invalid option...");
        break;
    }

    wait;
    return 0;
}