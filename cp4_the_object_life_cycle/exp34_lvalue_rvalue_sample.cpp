#include <iostream>
#include <cstring>
#include <utility>

class String {
public:
    String() = default;

     /*
      * If this constructor is explicit, then we can not creat Entity object with string literals.
      * there won't be an implicit constructor available to be called by Entity constructor
      */
    String(const char *string)
    {
        printf("Created!\n");
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }



/*
 * If user defined copy constructor is not available, compiler will provide a default constructor,
 * which does a member-wise copy of the object. This would cause unexpected behavior. Such as printing
 * garbage.
 * If you don't want the default copy constructor take place, use "delete" keyword to suppress it.
 */

//    String(const String &) = delete;
//
//    String &operator=(const String &) = delete;

    String(const String& other) {
        printf("Copied!\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
    }
    String(String&& other) noexcept{
        printf("Moved!\n");
        m_Size = other.m_Size;
        m_Data = other.m_Data;
        other.m_Data = nullptr;
        other.m_Size = 0;
    }
    ~String()
    {
        delete m_Data;
    }
    void print()
    {
        for (uint32_t i = 0; i < m_Size; i++) {
            printf("%c", m_Data[i]);
        }
        printf("\n");
    }
private:
    char *m_Data;
    uint32_t m_Size;
};

class Entity
{
public:
    /*
     * When a string literal is passed to Entity constructor, String::String(const char* x) will be invoked
     * first; then, the reference to that newly constructed String will be passed to Entity constructor's
     * initialization step, m_Name{name}. At this point, name is a String&; the initialization step
     * m_Name{name} will be looking for a constructor that takes String& as parameter;
     * String(const String& x), which usually is the copy constructor.
     */
    explicit Entity(const String& name)
        : m_Name{name}
    {
        printf("Copy entity created!\n");
    }

    explicit Entity(String &&name)
        :m_Name{std::move(name)}
    {
        printf("Move entity created!\n");
    }

    void PrintName(){
        m_Name.print();
    }
private:
    String m_Name;
};

int main() {
    String a{"Test Copy"};
//    Entity entity_copy{a};
//    entity_copy.PrintName();
    Entity entity_move{std::move(a)};
    entity_move.PrintName();
//    std::cin.get();
}