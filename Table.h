//
// Created by Fedor Zsombor on 2018. 02. 14..
//

#ifndef JOIN_TABLES_H
#define JOIN_TABLES_H


class Table{
public:
    struct Column{
        std::string name;
        std::string type;
        Column(std::string name, std::string type): name(name), type(type){}
    };
private:
    std::string filePath;
    std::ifstream file;
    std::vector<Column> columns;
    int rowNumber;
    //std::vector<std::array> tableData;

public:
    Table(std::string filePath){
        this->filePath=filePath;
        rowNumber = 0;
        open();
        loadTableData();



    }


    bool open(){

        file.open(filePath);
        std::string line;
        std::string delimiter = ",";
        size_t pos = 0;
        std::string token;
        getline(file,line);
        while ((pos = line.find(delimiter)) != std::string::npos) {     //parse the columns
            token = line.substr(0, pos);

            size_t posT = 0;
            posT = token.find(":");
            columns.push_back(Column(token.substr(0,posT), token.substr(posT+delimiter.length())));
            line.erase(0, pos + delimiter.length());
        }
        size_t posT = 0;
        posT = line.find(":");
        columns.push_back(Column(line.substr(0,posT), line.substr(posT+delimiter.length())));

        while (std::getline(file, line))    //count the rows
            ++rowNumber;

        std::cout << "Table " << filePath << " has " << columns.size() << " columns." << std::endl;

        return true;


    }

    bool loadTableData(){

    }



};


#endif //JOIN_TABLES_H
