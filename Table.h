//
// Created by Fedor Zsombor on 2018. 02. 14..
//

#ifndef JOIN_TABLES_H
#define JOIN_TABLES_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Field.h"


class Table {
public:
    struct Column {
        std::string name;
        std::string type;

        Column(std::string name, std::string type) : name(name), type(type) {}
    };





private:
    std::string filePath;
    std::ifstream file;
    std::vector<Column> columns;
    int rowNumber;


public:
    std::vector<std::vector<Field*>> tableData;


    Table(std::string filePath) {
        this->filePath = filePath;
        rowNumber = 0;
        open();
        loadTableData();

        //std::cout << *tableData[2][0];

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
            posT = token.find(':');
            columns.push_back(Column(token.substr(0, posT), token.substr(posT + delimiter.length())));
            line.erase(0, pos + delimiter.length());
        }
        size_t posT = 0;
        posT = line.find(':');
        columns.push_back(Column(line.substr(0, posT), line.substr(posT + delimiter.length())));

        // while (std::getline(file, line))    //count the rows
        //     ++rowNumber;

        for (int i = 0; i < columns.size(); ++i) {
            tableData.push_back(std::vector<Field*>());

        }

        //file.close();

        std::cout << "Table " << filePath << " has " << columns.size() << " columns." << std::endl;

        return true;


    }

    void loadTableData() {

        file.seekg(0, file.beg);
        std::string line;
        getline(file, line); //discarding the column headers

        while (std::getline(file, line)) {
            ++rowNumber;        //count the rows

            for (int i = 0; i < columns.size(); ++i) {

                std::string delimiter = ",";
                size_t pos = line.find(delimiter);
                std::string token = line.substr(0, pos);

                tableData[i].push_back(new Field(token, columns[i].type));


                line.erase(0, pos + delimiter.length());


            }
        }

    }




    int getColumnSize() {
        return (int) columns.size();
    }

    int getRowSize() {
        return rowNumber;
    }
    std::string getColumnName(int n){
        return columns[n].name;
    }




};


#endif //JOIN_TABLES_H
