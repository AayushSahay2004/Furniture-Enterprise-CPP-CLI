#include <iostream>
#include <string>

using namespace std;

class Furniture {
protected:
    float length, width, height;
    float cost;
    string material, design;

public:
    virtual void setDimensions() = 0;
    virtual void getDimensions() = 0;

    virtual void setCost() = 0;
    virtual void getCost() = 0;

    virtual void setMaterialAndDesign() = 0;
    virtual void getMaterialAndDesign() = 0;

    virtual void interact() = 0;
    virtual void display() = 0;

    virtual ~Furniture() {}
};

class Bookshelf : public Furniture {
private:
    int numShelves;
public:
    void setDimensions() override {
        cout << "Enter Bookshelf dimensions (length width height in cm): ";
        cin >> length >> width >> height;
    }
    void getDimensions() override {
        cout << "Dimensions (L x W x H): " << length << " x " << width << " x " << height << " cm" << endl;
    }
    void setCost() override {
        cout << "Enter cost of the Bookshelf: ";
        cin >> cost;
    }
    void getCost() override {
        cout << "Cost:" << cost << endl;
    }
    void setMaterialAndDesign() override {
        cout << "Enter material: ";
        cin.ignore();
        getline(cin, material);
        cout << "Enter design: ";
        getline(cin, design);
    }
    void getMaterialAndDesign() override {
        cout << "Material: " << material << ", Design: " << design << endl;
    }
    void interact() override {
        cout << "\n--- Bookshelf Setup ---\n";
        setDimensions();
        setCost();
        setMaterialAndDesign();
        cout << "Enter number of shelves: ";
        cin >> numShelves;
    }
    void display() override {
        cout << "\n--- Bookshelf Details ---\n";
        getDimensions();
        getCost();
        getMaterialAndDesign();
        cout << "Number of Shelves: " << numShelves << endl;
    }
};

class Chair : public Furniture {
private:
    string category;
public:
    void setDimensions() override {
        cout << "Enter Chair dimensions (length width height in cm): ";
        cin >> length >> width >> height;
    }
    void getDimensions() override {
        cout << "Dimensions (L x W x H): " << length << " x " << width << " x " << height << " cm" << endl;
    }
    void setCost() override {
        cout << "Enter cost of the Chair: ";
        cin >> cost;
    }
    void getCost() override {
        cout << "Cost: " << cost << endl;
    }
    void setMaterialAndDesign() override {
        cout << "Enter material: ";
        cin.ignore();
        getline(cin, material);
        cout << "Enter design: ";
        getline(cin, design);
    }
    void getMaterialAndDesign() override {
        cout << "Material: " << material << ", Design: " << design << endl;
    }
    void interact() override {
        cout << "\n--- Chair Setup ---\n";
        setDimensions();
        setCost();
        setMaterialAndDesign();
        int choice;
        cout << "Choose category:\n";
        cout << "1. Office Chair\n";
        cout << "2. Home Chair\n";
        cout << "3. Dinner Chair\n";
        cout << "Enter choice (1-3): ";
        cin >> choice;
        switch (choice) {
            case 1: category = "Office"; break;
            case 2: category = "Home"; break;
            case 3: category = "Dinner"; break;
            default: category = "Unknown"; break;
        }
    }
    void display() override {
        cout << "\n--- Chair Details ---\n";
        getDimensions();
        getCost();
        getMaterialAndDesign();
        cout << "Category: " << category << " Chair" << endl;
    }
};

// Arrays to hold up to 100 of each type
Bookshelf* bookshelfList[100];
Chair* chairList[100];
int bookshelfCount = 0;
int chairCount = 0;

void showAllBookshelf() {
    if (bookshelfCount == 0) {
        cout << "\nNo Bookshelves available.\n";
        return;
    }
    for (int i = 0; i < bookshelfCount; ++i) {
        cout << "\nBookshelf #" << (i + 1) << ":\n";
        bookshelfList[i]->display();
    }
}
void showAllChairs() {
    if (chairCount == 0) {
        cout << "\nNo Chairs available.\n";
        return;
    }
    for (int i = 0; i < chairCount; ++i) {
        cout << "\nChair #" << (i + 1) << ":\n";
        chairList[i]->display();
    }
}

void instantiate() {
    int choice;
    do {
        cout << "\n===== Instantiate Menu =====\n";
        cout << "1. Add Bookshelf\n";
        cout << "2. Add Chair\n";
        cout << "3. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1 && bookshelfCount < 100) {
            Bookshelf* bs = new Bookshelf();
            bs->interact();
            bookshelfList[bookshelfCount++] = bs;
        } else if (choice == 2 && chairCount < 100) {
            Chair* ch = new Chair();
            ch->interact();
            chairList[chairCount++] = ch;
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice or limit reached. Try again.\n";
        }

    } while (choice != 3);
}

int main() {
    int mode;
    do {
        cout << "\n===== Main Menu =====\n";
        cout << "1. Instantiate Mode\n";
        cout << "2. View Mode\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> mode;
        switch (mode) {
            case 1:
                instantiate();
                break;
            case 2: {
                int viewChoice;
                cout << "\n--- View Mode ---\n";
                cout << "1. Show All Bookshelves\n";
                cout << "2. Show All Chairs\n";
                cout << "Enter choice: ";
                cin >> viewChoice;
                if (viewChoice == 1)
                    showAllBookshelf();
                else if (viewChoice == 2)
                    showAllChairs();
                else
                    cout << "Invalid option.\n";
                break;
            }
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (mode != 3);

    // Cleanup
    for (int i = 0; i < bookshelfCount; ++i)
        delete bookshelfList[i];
    for (int i = 0; i < chairCount; ++i)
        delete chairList[i];

    return 0;
}
