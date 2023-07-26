//
// Created by wbai on 7/25/2023.
//
#define FMT_HEADER_ONLY
#include "cereal/archives/json.hpp"
#include "cereal/types/vector.hpp"
#include <fmt/format.h>
#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <vector>


class Record {
    // declare serialze as a friend for direct access to private data
    template<typename Archive>
    friend void serialize(Archive &archive, Record &record);

public:
    explicit Record(int account = 0, std::string_view first = "", std::string_view last = "", double balance = 0.0)
    : m_account{account}, m_first(first), m_last(last), m_balance(balance){};

    [[nodiscard]] int getAccount() const { return m_account; }
    [[nodiscard]] const std::string& getFirst() const { return m_first; }
    [[nodiscard]] const std::string& getLast() const { return m_last; }
    [[nodiscard]] double getBalance() const { return m_balance; }

private:
    int m_account{};
    std::string m_first{};
    std::string m_last{};
    double m_balance{};
};

template<typename Archive>
void serialize(Archive &archive, Record &record) {
    archive(cereal::make_nvp("account", record.m_account),
            cereal::make_nvp("first", record.m_first),
            cereal::make_nvp("last", record.m_first),
            cereal::make_nvp("balance", record.m_balance));
}

void displayRecords(const std::vector<Record> &records){
    for (const auto &r: records) {
        std::cout << fmt::format("{} {} {} {:.2f}\n", r.getAccount(), r.getFirst(), r.getLast(), r.getBalance());
    }
}

int main() {
    std::vector records{
            Record{100, "Brian", "Blue", 123.45},
            Record{200, "Sue", "Green", 9878.65}
    };

    std::cout << "Records to serialize:\n";
    displayRecords(records);

    // serialize vector of Records to JSON and store in text file
    if (std::ofstream output{"records2.json"}) {
        cereal::JSONOutputArchive archive{output};
        archive(cereal::make_nvp("records", records));
    }

    // deserialize JSON from text file into vector of Records
    if (std::ifstream input{"records2.json"}) {
        cereal::JSONInputArchive archive{input};
        std::vector<Record> deserializedRecords{};
        archive(deserializedRecords);
        std::cout << "\nDeserialized records:\n";
        displayRecords(deserializedRecords);
    }
}