#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <chrono>

enum class VehicleType
{
    CAR,
    TRUCK,
    BIKE
};
class Vehicle
{
private:
    int vehicleId;
    VehicleType vehicleType;

public:
    explicit Vehicle(int id, VehicleType type) : vehicleId(id), vehicleType(type) {}
    int getVehicleId() const;
    VehicleType getVehicleType() const;
};

int Vehicle::getVehicleId() const
{
    return vehicleId;
}

VehicleType Vehicle::getVehicleType() const
{
    return vehicleType;
}

class ParkingSpot
{
private:
    int spotId;
    VehicleType spotType;
    bool isAvailable;

public:
    ParkingSpot(int id, VehicleType type, bool isAvailable = true) : spotId(id), spotType(type), isAvailable(isAvailable) {}
    bool isSpotAvailable(VehicleType type) const;
    void occupySpot();
    void releaseSpot();
    int getParkingSpotId() const
    {
        return spotId;
    }
};

bool ParkingSpot::isSpotAvailable(VehicleType type) const
{
    if (spotType == type && isAvailable == true)
    {
        return true;
    }
    return false;
}

void ParkingSpot::occupySpot()
{
    isAvailable = false;
}

void ParkingSpot::releaseSpot()
{
    isAvailable = true;
}

class ParkingFloor
{
private:
    std::vector<std::unique_ptr<ParkingSpot>> spots;
    int floorNo;

public:
    explicit ParkingFloor(int floor) : floorNo(floor) {}
    std::vector<ParkingSpot *> getAvailableSpots(VehicleType type);
    void addSpots(int spotId, VehicleType type);
    ParkingSpot *getParkingSpot(int spotId);
    int getFloorNo() { return floorNo; }
};

void ParkingFloor::addSpots(int spotId, VehicleType type)
{
    spots.push_back(std::make_unique<ParkingSpot>(spotId, type));
}

std::vector<ParkingSpot *> ParkingFloor::getAvailableSpots(VehicleType type)
{
    std::vector<ParkingSpot *> parkingSpots;
    for (const auto &spot : spots)
    {
        if (spot->isSpotAvailable(type))
        {
            parkingSpots.emplace_back(spot.get());
        }
    }
    return parkingSpots;
}

ParkingSpot *ParkingFloor::getParkingSpot(int spotId)
{
    for (const auto &spot : spots)
    {
        if (spot->getParkingSpotId() == spotId)
            return spot.get();
    }
    return nullptr;
}

class ParkingLot
{
private:
    std::vector<std::unique_ptr<ParkingFloor>> floors;

public:
    void addFloors(int floorNo);
    std::vector<ParkingFloor *> getAvailableFloors(VehicleType type);
    ParkingSpot *getParkingSpot(int spotId)
    {
        for (const auto &floor : floors)
        {
            auto spot = floor->getParkingSpot(spotId);
            if (spot != nullptr)
                return spot;
        }
        return nullptr;
    }
    ParkingFloor *getParkingFloor(int floorNo)
    {
        for (const auto &floor : floors)
        {
            if (floor->getFloorNo() == floorNo)
                return floor.get();
        }
        return nullptr;
    }
};

void ParkingLot::addFloors(int floorNo)
{
    floors.emplace_back(std::make_unique<ParkingFloor>(floorNo));
}
std::vector<ParkingFloor *> ParkingLot::getAvailableFloors(VehicleType type)
{
    std::vector<ParkingFloor *> pFloor;
    for (const auto &floor : floors)
    {
        auto parkingSpots = floor->getAvailableSpots(type);
        if (!parkingSpots.empty())
            pFloor.emplace_back(floor.get());
    }
    return pFloor;
}

class ParkingStrategy
{
public:
    virtual ParkingSpot *findParking(VehicleType type) = 0;
    virtual ~ParkingStrategy() = default;
};

class FirstAvailableParking : public ParkingStrategy
{
private:
    ParkingLot *parkingLot;

public:
    ParkingSpot *findParking(VehicleType type) override;
    FirstAvailableParking(ParkingLot *pLot) : parkingLot(pLot) {}
};

ParkingSpot *FirstAvailableParking::findParking(VehicleType type)
{
    for (const auto &floor : parkingLot->getAvailableFloors(type))
    {
        auto parkingSpot = floor->getAvailableSpots(type);
        if (!parkingSpot.empty())
        {
            return parkingSpot.front();
        }
    }
    return nullptr;
}

class Ticket
{
private:
    int ticketId;
    int spotId;
    std::chrono::system_clock::time_point entranceTime;
    std::chrono::system_clock::time_point exitTime;
    int vehicleId;
    VehicleType vehicleType;

public:
    void getTicketDetails() const;
    explicit Ticket(int ticketId, int spotId, const Vehicle &vehicle) : ticketId(ticketId),
                                                                        spotId(spotId),
                                                                        entranceTime(std::chrono::system_clock::now()),
                                                                        exitTime{},
                                                                        vehicleId(vehicle.getVehicleId()),
                                                                        vehicleType(vehicle.getVehicleType())
    {
    }
    double durationInHours() const;
    int getVehicleId() const;
    VehicleType getVehicleType() const;
    int getSpotId() const { return spotId; }
    void setExitTime();
};

int Ticket::getVehicleId() const
{
    return vehicleId;
}

VehicleType Ticket::getVehicleType() const
{
    return vehicleType;
}

void Ticket::setExitTime()
{
    exitTime = std::chrono::system_clock::now();
}

double Ticket::durationInHours() const
{
    if (exitTime == std::chrono::system_clock::time_point{})
        return 0.0;
    auto duration = exitTime - entranceTime;
    return std::chrono::duration<double, std::ratio<3600>>(duration).count();
}

void Ticket::getTicketDetails() const
{
    // std::cout << "Vehicle ID: " << vehicleId << "\n "
    //           << "Ticket ID: " << ticketId << "\n"
    //           << "Spot Id: " << spotId << "\n"
    //           << "Entrance Time: " << entranceTime << "\n"
    //           << "Exit Time: " << exitTime << "\n";
}

class FeeCalculationStrategy
{
public:
    virtual double calculateFee(const Ticket &ticket) = 0;
    virtual ~FeeCalculationStrategy() = default;
};

class HourlyFee : public FeeCalculationStrategy
{
public:
    double calculateFee(const Ticket &ticket) override;
};

double HourlyFee::calculateFee(const Ticket &ticket)
{
    auto duration = ticket.durationInHours();
    switch (ticket.getVehicleType())
    {
    case VehicleType::CAR:

        return 100 * duration;

    case VehicleType::TRUCK:

        return 200 * duration;

    case VehicleType::BIKE:

        return 50 * duration;

    default:
        return 0;
    }
}

class PaymentMethod
{
public:
    virtual bool pay(const double amount) = 0;
    virtual ~PaymentMethod() = default;
};

class UPIPayment : public PaymentMethod
{
    int upiId;
    int transactionNo;

public:
    bool pay(const double amount) override;
    ~UPIPayment() = default;
};

bool UPIPayment::pay(const double amount)
{
    std::cout << "Upi Payment done for rs " << amount << "\n";
    return true;
}

class TicketManager
{
private:
    std::vector<std::unique_ptr<Ticket>> tickets;
    int ticketId = 0;

public:
    Ticket *createTicket(int spotId, const Vehicle &);
    // can have a ticket lookup if needed (map to store ticketId against VehicleId or Vehicle )
};

Ticket *TicketManager::createTicket(int spotId, const Vehicle &vehicle)
{
    auto ticket = std::make_unique<Ticket>(ticketId++, spotId, vehicle);
    Ticket *pTicket = ticket.get();
    tickets.emplace_back(std::move(ticket));
    return pTicket;
}

class ParkingService
{
private:
    TicketManager *pTicketMgr;
    ParkingStrategy *pParkStrategy;
    ParkingLot *pParkingLot;

public:
    Ticket *
    park(const Vehicle &vehicle);
    bool releaseParking(Ticket &ticket, FeeCalculationStrategy &pFeeStrategy, PaymentMethod &pPayment);

    ParkingService(TicketManager *ticketMgr, ParkingStrategy *parkStrategy, ParkingLot *parkingLot) : pTicketMgr(ticketMgr),
                                                                                                      pParkStrategy(parkStrategy),
                                                                                                      pParkingLot(parkingLot) {}
};

Ticket *ParkingService::park(const Vehicle &vehicle)
{
    auto spot = pParkStrategy->findParking(vehicle.getVehicleType());
    if (spot != nullptr)
    {
        spot->occupySpot();
        auto ticket = pTicketMgr->createTicket(spot->getParkingSpotId(), vehicle);
        return ticket;
    }
    else
        return nullptr;
}

bool ParkingService::releaseParking(Ticket &ticket, FeeCalculationStrategy &pFeeStrategy, PaymentMethod &pPayment)
{
    auto spot = pParkingLot->getParkingSpot(ticket.getSpotId());
    if (spot == nullptr)
    {
        std::cout << "No Parking Found .. !!! \n";
        return false;
    }
    ticket.setExitTime();
    double paymentAmount = pFeeStrategy.calculateFee(ticket);
    if (pPayment.pay(paymentAmount))
    {
        spot->releaseSpot();
        return true;
    }
    else
    {
        std::cout << "Payment is Due... cant release Parking until paid...!!! \n";
        return false;
    }
}

int main()
{
    ParkingLot parkingLot;
    parkingLot.addFloors(1);
    parkingLot.addFloors(2);
    parkingLot.addFloors(3);

    auto floor1 = parkingLot.getParkingFloor(1);
    auto floor2 = parkingLot.getParkingFloor(2);
    auto floor3 = parkingLot.getParkingFloor(3);

    if (floor1 != nullptr)
    {
        floor1->addSpots(100, VehicleType::CAR);
        std::cout << "Added spots to Floor 1 \n";
    }
    if (floor2 != nullptr)
    {
        floor2->addSpots(101, VehicleType::CAR);
        std::cout << "Added spots to Floor 2 \n";
    }
    if (floor3 != nullptr)
    {
        floor3->addSpots(102, VehicleType::BIKE);
        std::cout << "Added spots to Floor 3 \n";
    }

    TicketManager ticketMgr;
    FirstAvailableParking firstParking(&parkingLot);

    ParkingService pParkingService(&ticketMgr, &firstParking, &parkingLot);

    Vehicle vehicle1(1, VehicleType::CAR);
    Ticket *ticket = pParkingService.park(vehicle1);

    if (ticket != nullptr)
    {
        std::cout << "Vehicle Parked with spotId: " << ticket->getSpotId();
        std::cout << "\n Ticket Details: \n";
        ticket->getTicketDetails();
    }
    else
    {
        std::cout << "Parking Failed...!!! \n";
    }

    Vehicle vehicle2(2, VehicleType::CAR);
    ticket = pParkingService.park(vehicle2);

    if (ticket != nullptr)
    {
        std::cout << "Vehicle Parked with spotId: " << ticket->getSpotId();
        std::cout << "\n Ticket Details: \n";
        ticket->getTicketDetails();
    }
    else
    {
        std::cout << "Parking Failed...!!! \n";
    }
    Vehicle vehicle3(3, VehicleType::CAR);
    ticket = pParkingService.park(vehicle2);

    if (ticket != nullptr)
    {
        std::cout << "Vehicle Parked with spotId: " << ticket->getSpotId();
        std::cout << "\n Ticket Details: \n";
        ticket->getTicketDetails();
    }
    else
    {
        std::cout << "Parking Failed...!!! \n";
    }

    return 0;
}
