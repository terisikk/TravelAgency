#include <stdexcept>
#include <string>

#include "tsv/query.hpp"
#include "tsv/table.hpp"

#include "ui/context.hpp"

#include "TravelAgencyConfig.h"
#include "agency_query_state.hpp"
#include "appcontext.hpp"
#include "customer_query_state.hpp"
#include "delete_travel_state.hpp"
#include "driver_for_customer_query_state.hpp"
#include "driver_query_state.hpp"
#include "insert_travel_state.hpp"
#include "select_operation_state.hpp"
#include "travel_for_customer_query_state.hpp"
#include "travel_query_state.hpp"


auto main() -> int
{
    try {
        std::cout << "Loading database...";

        tsv::Table agencies({"ID", "NAME", "RDATE", "SCOUNT", "CNAME"});
        agencies.populate("agencies.txt");

        tsv::Table customers({"ID", "NAME", "PHONE", "ADDRESS"});
        customers.populate("customers.txt");

        tsv::Table drivers({"ID", "AID", "NAME", "EDATE", "CAR"});
        drivers.populate("drivers.txt");

        tsv::Table travels({"ID", "DID", "STIME", "CID", "ORIGIN", "DESTINATION", "PAYMENT"});
        travels.populate("travels.txt");

        std::cout << " done." << std::endl;

        AgencyQueryState agencyQueryState(&agencies);
        DriverQueryState driverQueryState(&drivers);
        CustomerQueryState customerQueryState(&customers);
        TravelQueryState travelQueryState(&travels);
        TravelForCustomerQueryState travelForCustomerQueryState(&travels);
        DriverForCustomerQueryState driverForCustomerQueryState(&drivers, &travels);
        InsertTravelState insertTravelState(&travels);
        DeleteTravelState deleteTravelState(&travels);

        SelectOperationState selectOperationState;
        selectOperationState.addOperationState("Find an agency", &agencyQueryState);
        selectOperationState.addOperationState("Find a driver", &driverQueryState);
        selectOperationState.addOperationState("Find a customer", &customerQueryState);
        selectOperationState.addOperationState("Insert a new travel", &insertTravelState);
        selectOperationState.addOperationState("Delete a travel", &deleteTravelState);
        selectOperationState.addOperationState("Find a travel", &travelQueryState);
        selectOperationState.addOperationState("Find customer travels", &travelForCustomerQueryState);
        selectOperationState.addOperationState("Find customer drivers", &driverForCustomerQueryState);

        AppContext uiContext(&selectOperationState);

        while(true) {
            std::cout << uiContext.getOutput();

            std::string input;
            std::getline(std::cin, input);

            std::string queryResult = uiContext.getOutput(input);
            
            std::cout << std::endl << queryResult << std::endl;

            if (!queryResult.empty()) {
                uiContext.tranisitionToDefaultState();
            }
        }

    } catch (...) {
        return 0;
    }

    return 0;
}
