#pragma once

#include <map>

#include "common/chunks_availability_state.h"
#include "utils/lizardfs_probe/lizardfs_probe_command.h"

class ChunksHealthCommand : public LizardFsProbeCommand {
public:
	virtual std::string name() const;
	virtual void usage() const;
	virtual void run(const std::vector<std::string>& argv) const;

	static std::vector<uint8_t> collectGoals();
	static std::map<uint8_t, std::string> createGoalNames();

private:
	static const std::vector<uint8_t> kGoals;
	static const std::map<uint8_t, std::string> kGoalNames;
	static const std::string kOptionAll;
	static const std::string kOptionAvailability;
	static const std::string kOptionReplication;
	static const std::string kOptionDeletion;

	void printState(const ChunksAvailabilityState& state, bool isPorcelain) const;
	void printState(bool isReplication, const ChunksReplicationState& state,
			bool isPorcelain) const;
	std::string print(uint64_t number) const;
};
