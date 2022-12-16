// Copyright 2022 The Tool Shed (Chris Garnier)

#pragma once

#include "CoreMinimal.h"

/**
 * RecentBlueprintMenu class containing functions to use by the menus
 */


class RECENTBLUEPRINTMENU_API FRecentBlueprintMenuUtils
{
	friend class FRecentBlueprintMenuModule; //TODO: Only friend the necessary classes

private:
	//Called when a blueprint opens, so it can get saved to the recent list
	static void OnBlueprintOpened(FString BlueprintPath);

	//Remove files that do not exist anymore
	static void PurgeList();

};
