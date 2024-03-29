/**
 * @author Marcos Portnoi
 * @date July 2013
 * 
 * @copyright Copyright (C) 2013 University of Delaware.
 * @copyright QCNSim uses elements of TARVOS simulator, Copyright (C) 2005, 2006, 2007 Marcos Portnoi.
 * @par
 * This file is part of QCNSim.  QCNSim is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.<br>
 * QCNSim is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.<br>
 * You should have received a copy of the GNU Lesser General Public License
 * along with QCNSim.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "ExponentialTrafficGenerator.h"

/**
 * Constructor with parameter.
 *
 * @details 
 * The seed for the random number generator is controlled by SimulatorGlobals. If none is ever specified, random_device output is used as seed.
 * 
 * @param simulatorGlobals Reference to SimulatorGlobals object, to get random generator info.
 * @param scheduler Reference to Scheduler object, such that traffic generators may schedule their events.
 * @param eventType Event type that this generator will produce.
 * @param tokenContents Reference to Entity object that will be carried by the token.
 * @param source Entity to which the generator is attached (to which tokens are generated).
 * @param destination Destination entity, to which the generated tokens will be sent.
 * @param priority Token priority. Higher priority, higher number.
 * @param tau Mean interarrival time (or inverse rate or arrival, lambda) for exponential probability distribution.
 */
ExponentialTrafficGenerator::ExponentialTrafficGenerator(SimulatorGlobals &simulatorGlobals, Scheduler &scheduler, EventType eventType, std::shared_ptr<Entity> tokenContents,
		std::shared_ptr<Entity> source, std::shared_ptr<Entity> destination, int priority, double tau): TrafficGenerator(simulatorGlobals, scheduler, eventType, tokenContents,
		source, destination, priority), tau(tau) {
	//this->tau = tau;
	//exponentialDistribution(tau);
}

/**
 * Constructor with parameters, seed as parameter.
 *
 * @param simulatorGlobals Reference to SimulatorGlobals object, to get random generator info.
 * @param scheduler Reference to Scheduler object, such that traffic generators may schedule their events.
 * @param eventType Event type that this generator will produce.
 * @param tokenContents Reference to Entity object that will be carried by the token.
 * @param source Entity to which the generator is attached (to which tokens are generated).
 * @param destination Destination entity, to which the generated tokens will be sent.
 * @param priority Token priority. Higher priority, higher number.
 * @param tau Mean interarrival time (or inverse rate or arrival, lambda) for exponential probability distribution.
 * @param seed Seed to the default random number generator, to be passed to SimulatorGlobals object.
 */
ExponentialTrafficGenerator::ExponentialTrafficGenerator(SimulatorGlobals &simulatorGlobals, Scheduler &scheduler, EventType eventType, std::shared_ptr<Entity> tokenContents,
		std::shared_ptr<Entity> source, std::shared_ptr<Entity> destination, int priority, double tau, unsigned int seed): TrafficGenerator(simulatorGlobals, scheduler, eventType, tokenContents,
		source, destination, priority, seed), tau(tau) {
	//this->tau = tau;
	//exponentialDistribution.;
}

/**
 * Creates an instance of exponential traffic event.
 *
 * @details 
 * Calls parent function and complements with event generation and exponential random variate.
 * Uses member variable tokenContents.
 *
 * @param recordRoute True if this generated token should record the route it follows. False otherwise. Default is false.
 * @return Token that was generated, per the class constructor parameters and if generator is On. Otherwise, returns nullptr.
 */
std::shared_ptr<Token> ExponentialTrafficGenerator::createInstanceTrafficEvent(bool recordRoute) {
	// Creates a token and assigns it class member values and a unique ID obtained from simulatorGlobals.
	std::shared_ptr<Token> token = TrafficGenerator::createInstanceTrafficEvent(recordRoute);
	if (token != nullptr) {
		scheduler.schedule(Event(generateExponentialVariate(), eventType, token));
	}
	return token;
}

/**
 * Creates an instance of exponential traffic event.
 *
 * @details 
 * Calls parent function and complements with event generation and exponential random variate.
 * Uses parameter tokenContents.
 *
 * @param tokenContents Reference to Entity object that will be carried by the token.
 * @param recordRoute True if this generated token should record the route it follows. False otherwise. Default is false.
 *
 * @return Token that was generated, per the class constructor parameters and if generator is On. Otherwise, returns nullptr.
 */
std::shared_ptr<Token> ExponentialTrafficGenerator::createInstanceTrafficEvent(std::shared_ptr<Entity> tokenContents, bool recordRoute) {
	// Creates a token and assigns it class member values and a unique ID obtained from simulatorGlobals.
	std::shared_ptr<Token> token = TrafficGenerator::createInstanceTrafficEvent(tokenContents, recordRoute);
	if (token != nullptr) {
		scheduler.schedule(Event(generateExponentialVariate(), eventType, token));
	}
	return token;
}

/**
 * Creates an instance of exponential traffic event.
 *
 * @details 
 * Calls parent function and complements with event generation and exponential random variate.
 * Uses member variable tokenContents and parameter explicit route.
 *
 * @param explicitRoute Vector containing a list of Entity objects representing the route to be followed by a token/PDU.
 * @param recordRoute True if this generated token should record the route it follows. False otherwise. Default is false.
 *
 * @return Token that was generated, per the class constructor parameters and if generator is On. Otherwise, returns nullptr.
 */
std::shared_ptr<Token> ExponentialTrafficGenerator::createInstanceTrafficEvent(std::vector<std::shared_ptr<Entity>> explicitRoute, bool recordRoute) {
	// Creates a token and assigns it class member values and a unique ID obtained from simulatorGlobals.
	std::shared_ptr<Token> token = TrafficGenerator::createInstanceTrafficEvent(explicitRoute, recordRoute);
	if (token != nullptr) {
		scheduler.schedule(Event(generateExponentialVariate(), eventType, token));
	}
	return token;
}

/**
 * Creates an instance of exponential traffic event.
 *
 * @details 
 * Calls parent function and complements with event generation and exponential random variate.
 * Uses parameter tokenContents and explicit route.
 *
 * @param tokenContents Reference to Entity object that will be carried by the token.
 * @param explicitRoute Vector containing a list of Entity objects representing the route to be followed by a token/PDU.
 * @param recordRoute True if this generated token should record the route it follows. False otherwise. Default is false.
 *
 * @return Token that was generated, per the class constructor parameters and if generator is On. Otherwise, returns nullptr.
 */
std::shared_ptr<Token> ExponentialTrafficGenerator::createInstanceTrafficEvent(std::shared_ptr<Entity> tokenContents, std::vector<std::shared_ptr<Entity>> explicitRoute, bool recordRoute) {
	// Creates a token and assigns it class member values and a unique ID obtained from simulatorGlobals.
	std::shared_ptr<Token> token = TrafficGenerator::createInstanceTrafficEvent(tokenContents, explicitRoute, recordRoute);
	if (token != nullptr) {
		scheduler.schedule(Event(generateExponentialVariate(), eventType, token));
	}
	return token;
}


/**
 * Generate an exponential distribution variate based on member variable tau.
 *
 * @details 
 * The exponential variate is generated using C++11 Random library and uses the random number generator obtained from SimulatorGlobals,
 * such that its global seed can be utilized.
 *
 * @return Exponential distribution variate based on member variable tau.
 */
double ExponentialTrafficGenerator::generateExponentialVariate() {
	// Have not seen different behavior with or without static below, per unit testing.
	// The pseudorandom sequence seems to be unique per simulation, not per generator; the former is the expected behavior.
	//static std::exponential_distribution<double> exponentialGenerator(tau);
	std::exponential_distribution<double> exponentialGenerator(1/tau); // !!! Notice that the exponential generator takes lambda (from Poisson), not tau!!!
	return exponentialGenerator(simulatorGlobals.getRandomNumberGeneratorEngineInstance());
}

/**
 * Returns tau (interarrival time).
 *
 * @return Tau.
 */
double ExponentialTrafficGenerator::getTau() const {
	return tau;
}

/**
 * @brief Creates an instance of exponential traffic event with PDU.
 *
 * @param pduSize Size of PDU to generate.
 * @param recordRoute True if this generated token should record the route it follows. False otherwise. Default is false.
 *
 * @return PDU that was generated, per the class constructor parameters and if generator is On. Otherwise, returns nullptr.
 */
std::shared_ptr<ProtocolDataUnit> ExponentialTrafficGenerator::createInstanceTrafficEventPdu(unsigned int pduSize, bool recordRoute) {
	// Creates a PDU and assigns it class member values and a unique ID obtained from simulatorGlobals.
	// Notice that the base class member function "createInstance..." is used here instead of the derived override:
	// the derived override schedules an event, and that is undesired here, since an event can only be scheduled "after" the PDU is created.
	std::shared_ptr<Token> token = TrafficGenerator::createInstanceTrafficEvent(recordRoute);
	if (token == nullptr) {
		return nullptr;
	}
	//std::shared_ptr<ProtocolDataUnit> pdu(new ProtocolDataUnit(TrafficGenerator::createInstanceTrafficEvent(recordRoute), pduSize));
	std::shared_ptr<ProtocolDataUnit> pdu(new ProtocolDataUnit(token, pduSize));
	if (pdu != nullptr) {
		scheduler.schedule(Event(generateExponentialVariate(), eventType, pdu));
	}
	return pdu;
}

/**
 * @brief Creates an instance of exponential traffic event.
 *
 * @param pduSize Size of PDU to generate.
 * @param pduContents Reference to Entity object that will be carried by the token.
 * @param recordRoute True if this generated token should record the route it follows. False otherwise. Default is false.
 *
 * @return PDU that was generated, per the class constructor parameters and if generator is On. Otherwise, returns nullptr.
 */
std::shared_ptr<ProtocolDataUnit> ExponentialTrafficGenerator::createInstanceTrafficEventPdu(unsigned int pduSize, std::shared_ptr<Entity> pduContents,
																						   bool recordRoute) {
	// Creates a PDU and assigns it class member values and a unique ID obtained from simulatorGlobals.
	std::shared_ptr<Token> token = TrafficGenerator::createInstanceTrafficEvent(pduContents, recordRoute);
	if (token == nullptr) {
		return nullptr;
	}
	std::shared_ptr<ProtocolDataUnit> pdu(new ProtocolDataUnit(token, pduSize));
	//std::shared_ptr<ProtocolDataUnit> pdu(new ProtocolDataUnit(TrafficGenerator::createInstanceTrafficEvent(pduContents, recordRoute), pduSize));
	if (pdu != nullptr) {
		scheduler.schedule(Event(generateExponentialVariate(), eventType, pdu));
	}
	return pdu;
}

/**
 * @brief Creates an instance of exponential traffic event.
 *
 * @param pduSize Size of PDU to generate.
 * @param explicitRoute Vector containing a list of Entity objects representing the route to be followed by a token/PDU.
 * @param recordRoute True if this generated token should record the route it follows. False otherwise. Default is false.
 *
 * @return PDU that was generated, per the class constructor parameters and if generator is On. Otherwise, returns nullptr.
 */
std::shared_ptr<ProtocolDataUnit> ExponentialTrafficGenerator::createInstanceTrafficEventPdu(unsigned int pduSize, std::vector<std::shared_ptr<Entity>> explicitRoute,
																						   bool recordRoute) {
	// Creates a PDU and assigns it class member values and a unique ID obtained from simulatorGlobals.
	std::shared_ptr<Token> token = TrafficGenerator::createInstanceTrafficEvent(explicitRoute, recordRoute);
	if (token == nullptr) {
		return nullptr;
	}
	std::shared_ptr<ProtocolDataUnit> pdu(new ProtocolDataUnit(token, pduSize));
	//std::shared_ptr<ProtocolDataUnit> pdu(new ProtocolDataUnit(TrafficGenerator::createInstanceTrafficEvent(explicitRoute, recordRoute), pduSize));
	if (pdu != nullptr) {
		scheduler.schedule(Event(generateExponentialVariate(), eventType, pdu));
	}
	return pdu;
}

/**
 * @brief Creates an instance of exponential traffic event.
 *
 * @param pduSize Size of PDU to generate.
 * @param tokenContents Reference to Entity object that will be carried by the token.
 * @param explicitRoute Vector containing a list of Entity objects representing the route to be followed by a token/PDU.
 * @param recordRoute True if this generated token should record the route it follows. False otherwise. Default is false.
 *
 * @return PDU that was generated, per the class constructor parameters and if generator is On. Otherwise, returns nullptr.
 */
std::shared_ptr<ProtocolDataUnit> ExponentialTrafficGenerator::createInstanceTrafficEventPdu(unsigned int pduSize, std::shared_ptr<Entity> tokenContents,
																						   std::vector<std::shared_ptr<Entity>> explicitRoute,
																						   bool recordRoute) {
	// Creates a PDU and assigns it class member values and a unique ID obtained from simulatorGlobals.
	std::shared_ptr<Token> token = TrafficGenerator::createInstanceTrafficEvent(tokenContents, explicitRoute, recordRoute);
	if (token == nullptr) {
		return nullptr;
	}
	std::shared_ptr<ProtocolDataUnit> pdu(new ProtocolDataUnit(token, pduSize));
	//std::shared_ptr<ProtocolDataUnit> pdu(new ProtocolDataUnit(TrafficGenerator::createInstanceTrafficEvent(tokenContents, explicitRoute, recordRoute), pduSize));
	if (pdu != nullptr) {
		scheduler.schedule(Event(generateExponentialVariate(), eventType, pdu));
	}
	return pdu;
}