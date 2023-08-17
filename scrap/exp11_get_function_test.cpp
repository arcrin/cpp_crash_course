#include <iostream>

class Entity{
public:
    Entity() = default;
    [[nodiscard]] const  std::string& getName() const { return m_Name; }

    static void printType() {
        std::cout << "Entity\n";
    }

private:
    Entity *m_Parent;
    std::string m_Name;
};

int main() {
    Entity *entity = new Entity();

}