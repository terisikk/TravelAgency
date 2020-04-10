#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "tsv/reader.hpp"
#include "tsv/table.hpp"
#include "tsv/query.hpp"

#include "TravelAgencyConfig.h"
#include "agency.hpp"


auto main() -> int
{
    std::ifstream ifs;
    ifs.open("agencies.txt", std::ios_base::in);

    tsv::Table<Agency> agencyTable("agencies");

    while(!ifs.eof()) {
        std::vector<std::string> items = tsv::Reader::readRow(ifs);
        if(!items.empty()) {
            Agency agency(items.at(0), items.at(1), items.at(2), items.at(3), items.at(4));
            agencyTable.insert(agency);
        }
    }

    tsv::Query<Agency, std::string> query("Agency#8", &Agency::getName);

    for(auto& agency : agencyTable.select(query)) {
        std::cout << agency.getName() << " " << agency.getRegisteredDate() << std::endl;
    }

    return 0;
}
