#pragma once
#include "Command.h"

class DuckCommand final : public dae::Command
{
public:
	DuckCommand(KeyActionState state = KeyActionState::pressed) : Command(state) {}
	DuckCommand(DuckCommand const& other) = delete;
	DuckCommand(DuckCommand&& other) = delete;
	DuckCommand& operator=(DuckCommand const& rhs) = delete;
	DuckCommand& operator=(DuckCommand&& rhs) = delete;
	~DuckCommand() override = default;

	bool Execute() override;
};