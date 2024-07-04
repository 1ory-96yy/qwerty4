#include <iostream>
#include <vector>
#include <string>
#include <memory>

class DirectoryEntry {
public:
    DirectoryEntry(const std::string& name, const std::string& owner,
        const std::string& phone, const std::string& address,
        const std::string& businessType)
        : name(name), owner(owner), phone(phone), address(address), businessType(businessType) {}

    std::string getName() const { return name; }
    std::string getOwner() const { return owner; }
    std::string getPhone() const { return phone; }
    std::string getAddress() const { return address; }
    std::string getBusinessType() const { return businessType; }

private:
    std::string name;
    std::string owner;
    std::string phone;
    std::string address;
    std::string businessType;
};

class Directory {
public:
    void addEntry(const DirectoryEntry& entry) {
        entries.push_back(entry);
    }

    std::shared_ptr<DirectoryEntry> findByName(const std::string& name) {
        for (auto& entry : entries) {
            if (entry.getName() == name) {
                return std::make_shared<DirectoryEntry>(entry);
            }
        }
        return nullptr;
    }

private:
    std::vector<DirectoryEntry> entries;
};

int main() {
    Directory directory;

    directory.addEntry(DirectoryEntry("Company1", "Owner1", "123-456-7890", "Address1", "BusinessType1"));
    directory.addEntry(DirectoryEntry("Company2", "Owner2", "234-567-8901", "Address2", "BusinessType2"));
    directory.addEntry(DirectoryEntry("Company3", "Owner3", "345-678-9012", "Address3", "BusinessType3"));

    std::string searchName = "Company2";
    std::shared_ptr<DirectoryEntry> result = directory.findByName(searchName);

    if (result) {
        std::cout << "Found entry for company '" << searchName << "':" << std::endl;
        std::cout << "Name: " << result->getName() << std::endl;
        std::cout << "Owner: " << result->getOwner() << std::endl;
        std::cout << "Phone: " << result->getPhone() << std::endl;
        std::cout << "Address: " << result->getAddress() << std::endl;
        std::cout << "Business Type: " << result->getBusinessType() << std::endl;
    }
    else {
        std::cout << "Entry for company '" << searchName << "' not found." << std::endl;
    }

    return 0;
}
