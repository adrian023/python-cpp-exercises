#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

struct Person {
    std::string nickname;
    std::string favoriteArtist;
    std::string favoriteSong;
};

int main(int argc, char* argv[]) {
    // Check if the correct command-line arguments are provided
    if (argc != 2) {
        std::cout << "Usage: personsInfo personsInfo.txt" << std::endl;
        return 1;
    }

    const char* file_path = argv[1];
    std::ifstream file(file_path);

    // Check if the file was successfully opened
    if (!file.is_open()) {
        std::cout << "File '" << file_path << "' not found." << std::endl;
        return 1;
    }

    std::vector<Person> persons;

    // Read the contents of the file
    std::string line;
    // Skip the header line
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string field;
        std::vector<std::string> fields;
        while (std::getline(ss, field, ',')) {
            fields.push_back(field);
        }

        // Check if there are at least 4 fields in the line
        if (fields.size() >= 4) {
            Person person;
            person.nickname = fields[1];
            person.favoriteArtist = fields[2];
            person.favoriteSong = fields[3];
            persons.push_back(person);
        }
    }

    // Print the content to the console
    std::cout << "Person  Nickname        Favorite Artist  Favorite Song" << std::endl;
    for (std::size_t i = 0; i < persons.size(); ++i) {
        const Person& person = persons[i];
        std::cout << std::left << std::setw(7) << i + 1 << "  "
                  << std::left << std::setw(15) << person.nickname << "  "
                  << std::left << std::setw(16) << person.favoriteArtist << "  "
                  << std::left << person.favoriteSong << std::endl;
    }

    // Close the file
    file.close();

    return 0;
}

