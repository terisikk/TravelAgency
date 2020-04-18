#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "tsv/query.hpp"
#include "tsv/reader.hpp"
#include "tsv/table.hpp"

#include "TravelAgencyConfig.h"
#include "agency.hpp"
#include "agencybuilder.hpp"


auto main() -> int
{
    std::ifstream ifs;
    ifs.open("agencies.txt", std::ios_base::in);

    tsv::Table<Agency> agencyTable("agencies");

    while(!ifs.eof()) {
        std::vector<std::string> items = tsv::Reader::readRow(ifs);
        if(!items.empty()) {
            Agency agency = AgencyBuilder::build(items);
            agencyTable.insert(agency);
        }
    }

    tsv::Query<Agency, std::string> query("Agency#8", &Agency::getName);

    for(auto& agency : agencyTable.select(query)) {
        std::cout << agency.getName() << " " << agency.getStaffCount() << std::endl;
    }

    return 0;
}
