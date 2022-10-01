#include <iostream>
#include <string>

using namespace std;

namespace Custom_STL
{

template <typename T1, typename T2>
struct Pair
{
  T1 key;
  T2 value;

  Pair() : key(T1()), value(T2()) {}

  Pair(T1 key, T2 value)
  {
    this->key = key;
    this->value = value;
  }
};

template <typename T1 = string, typename T2 = string, const int SIZE = 100>
class Dictionary
{
private:
  Pair<T1, T2> *array;
  int _write_index;

  Pair<T1, T2> *get_pair_reference(const T1 key) const
  {
    for (int i = 0; i < _write_index; i++)
    {
      if (array[i].key == key)
        return &array[i];
    }

    return 0;
  }

  bool check_for_unique_key(const T1 key) const
  {
    for (int i = 0; i < _write_index; i++)
    {
      if (array[i].key == key)
        return false;
    }

    return true;
  }

public:
  // constructor
  Dictionary()
  {
    _write_index = int();

    array = new Pair<T1, T2>[SIZE];
  }

  // setter methods
  void insert(const T1 key, const T2 value)
  {
    if (!check_for_unique_key(key))
    {
      cout << "\nkey " << key << " already exists";
      return;
    }

    Pair<T1, T2> keyValuePair = Pair<T1, T2>(key, value);
    array[_write_index++] = keyValuePair;

    return;
  }

  void update_value(const T1 key, const T2 newValue)
  {
    auto keyAddress = get_pair_reference(key);

    if (keyAddress)
      keyAddress->value = newValue;
    else
      cout << "\nkey " << key << " doesn't exists";

    return;
  }

  void update_key(const T1 oldKey, const T2 newKey)
  {
    if (!check_for_unique_key(newKey))
    {
      cout << "\nkey " << newKey << " already exists";
      return;
    }

    auto keyAddress = get_pair_reference(oldKey);

    if (keyAddress)
      keyAddress->key = newKey;
    else
      cout << "\nkey " << oldKey << " doesn't exists";

    return;
  }

  void delete_key(const T1 key)
  {
    for (int i = 0; i < _write_index; i++)
    {
      if (array[i].key == key)
      {
        for (int j = i; j < _write_index; j++)
          array[j] = array[j + 1];

        _write_index -= 1;
        return;
      }
    }

    cout << "\nkey " << key << " doesn't exists";

    return;
  }

  // getter method
  const T2 get_value(const T1 key) const
  {
    auto keyAddress = get_pair_reference(key);

    if (keyAddress)
      return keyAddress->value;

    cout << "\nkey " << key << " doesn't exists";

    return T2();
  }

  const int get_cardinality() const
  {
    return _write_index;
  }

  // pretty print
  void show_dict() const
  {
    cout << "\n{";
    for (int i = 0; i < _write_index; i++)
      cout << array[i].key << " : " << array[i].value << ",\n ";
    cout << "}";

    return;
  }
};

} // namespace Custom_STL

int main()
{
  Custom_STL::Dictionary<> dict;

  dict.insert("key0", "value0");
  dict.insert("key1", "value1");
  dict.insert("key2", "value2");
  dict.insert("key3", "value3");
  dict.insert("key4", "value4");
  dict.insert("key2", "value2");
  dict.insert("key5", "value5");
  dict.insert("key6", "value6");
  dict.insert("key7", "value7");

  dict.show_dict();

  dict.update_value("key11", "new_value1");
  dict.delete_key("key0");
  dict.update_key("key5", "new_key5");

  dict.show_dict();

  dict.insert("key1", "value1");

  dict.show_dict();

  return 0;
}