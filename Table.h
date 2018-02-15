//
// Created by Fedor Zsombor on 2018. 02. 14..
//

#ifndef JOIN_TABLES_H
#define JOIN_TABLES_H


class Table {
public:
    struct Column {
        std::string name;
        std::string type;

        Column(std::string name, std::string type) : name(name), type(type) {}
    };

    //enum for switch-case
    static enum typeValue {
        INT,
        STRING,
        LONG,
        CHAR,
        DOUBLE,
        SHORT
    };


private:
    std::string filePath;
    std::ifstream file;
    std::vector<Column> columns;
    int rowNumber;
    std::vector<std::array> tableData;

public:
    Table(std::string filePath) {
        this->filePath = filePath;
        rowNumber = 0;
        open();
        loadTableData();


    }


    bool open() {

        file.open(filePath);
        std::string line;
        std::string delimiter = ",";
        size_t pos = 0;
        std::string token;
        getline(file, line);
        while ((pos = line.find(delimiter)) != std::string::npos) {     //parse the columns
            token = line.substr(0, pos);
            size_t posT = 0;
            posT = token.find(":");
            columns.push_back(Column(token.substr(0, posT), token.substr(posT + delimiter.length())));
            line.erase(0, pos + delimiter.length());
        }
        size_t posT = 0;
        posT = line.find(":");
        columns.push_back(Column(line.substr(0, posT), line.substr(posT + delimiter.length())));

        while (std::getline(file, line))    //count the rows
            ++rowNumber;

        for (int i = 0; i < columns.size(); ++i) {

            switch (hashIt(columns[i].type)) {
                case INT:
                    std::vector<int> *tempI = new std::vector<int>();
                    tableData[i] = tempI;
                    break;
                case STRING:
                    std::vector<std::string> *tempS = new std::vector<std::string>();
                    tableData[i] = tempS;
                    break;
                case LONG:
                    std::vector<long> *tempL = new std::vector<long>();
                    tableData[i] = tempL;
                    break;
                case CHAR:
                    std::vector<char> *tempC = new std::vector<char>();
                    tableData[i] = tempC;
                    break;
                case DOUBLE:
                    std::vector<double> *tempD = new std::vector<double>();
                    tableData[i] = tempD;
                    break;
                case SHORT:
                    std::vector<short> *tempSh = new std::vector<short>();
                    tableData[i] = tempSh;
                    break;
                default:
                    std::cerr << "Error: Unsupported column type.";
            }


        }

        //file.close();

        std::cout << "Table " << filePath << " has " << columns.size() << " columns." << std::endl;

        return true;


    }

    bool loadTableData() {
        file.seekg(0, file.beg);
        std::string line;
        getline(file, line); //discarding the column headers

        while (std::getline(file, line)) {
            ++rowNumber;        //count the rows

            for (int i = 0; i < columns.size(); ++i) {

                std::string delimiter = ",";
                size_t pos = line.find(delimiter);
                std::string token = line.substr(0, pos);
                tableData[i].push_back(token);


            }
        }

    }

    template<typename T>

    T **createColumnData(int colNum) {
        T *data = new T[rowNumber]();
        tableData.insert(colNum, data);
    }


    typeValue hashIt(std::string const &inString) {
        if (inString == "int") return INT;
        if (inString == "string") return STRING;
        if (inString == "long") return LONG;
        if (inString == "char") return CHAR;
        if (inString == "double") return DOUBLE;
        if (inString == "short") return SHORT;
        std::cerr << "Error: Unsupported column type.";


        return NULL;

    }


};


#endif //JOIN_TABLES_H
