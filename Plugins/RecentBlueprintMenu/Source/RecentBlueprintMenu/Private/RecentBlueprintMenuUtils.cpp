// Copyright 2022 The Tool Shed (Chris Garnier)


#include "RecentBlueprintMenuUtils.h"
#include "RecentBlueprintMenuSettings.h"

void FRecentBlueprintMenuUtils::OnBlueprintOpened(FString BlueprintPath)
{
	
	TArray<FString>& RecentList = GetMutableDefault<URecentBlueprintMenuSettings>()->RecentBlueprints;
	const int32 Index = RecentList.Find(BlueprintPath);
	if (Index != INDEX_NONE) 	//If it's already in the list we just need to move it to the top
	{
		if (Index == 0) 
		{
			return; //already first
		} 
		RecentList.RemoveAt(Index); //removes so we can re-add at the end
	}
	RecentList.EmplaceAt(0, BlueprintPath);

	//Now that we've added, trim entries 
	const uint8 MaxBP = GetDefault<URecentBlueprintMenuSettings>()->MaxRecentBP;
	if (RecentList.Num() > MaxBP)
	{
		TArray<FString> TrimmedList;
		for (int i=0; i < RecentList.Num(); i++)
		{
			if (i < MaxBP)
			{
				TrimmedList.Add(RecentList[i]);				
			}
		}
		RecentList = TrimmedList;
	}
	
	GetMutableDefault<URecentBlueprintMenuSettings>()->SaveConfig();

}

void FRecentBlueprintMenuUtils::PurgeList()
{
	TArray<FString>& List = GetMutableDefault<URecentBlueprintMenuSettings>()->RecentBlueprints;
	
	TArray<FString> NewList;
	
	for (int32 i = 0; i < List.Num(); i++)
	{
		if (FPackageName::DoesPackageExist(List[i]))
		{
			NewList.Add(List[i]);
		}		
	}

	List = NewList;
	GetMutableDefault<URecentBlueprintMenuSettings>()->SaveConfig();
}
