// Copyright 2022 The Tool Shed (Chris Garnier)

#include "RecentBlueprintMenu.h"
#if ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 24
#include "Toolkits/AssetEditorManager.h"
#endif
#include "BlueprintEditor.h"
#include "RecentBlueprintMenuUtils.h"
#include "RecentBlueprintMenuSettings.h"
#include "EditorStyleSet.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Engine/LevelScriptBlueprint.h"

#define LOCTEXT_NAMESPACE "FRecentBlueprintMenuModule"

void FRecentBlueprintMenuModule::StartupModule()
{
	///ADD NEW BLUEPRINT MENU
	FBlueprintEditorModule& BlueprintEditorModule = FModuleManager::LoadModuleChecked<FBlueprintEditorModule>("Kismet");
	if (const TSharedPtr<FExtensibilityManager> MenuExtender = BlueprintEditorModule.GetMenuExtensibilityManager())
	{
		BlueprintMenuExtender = MakeShareable(new FExtender);
		BlueprintMenuExtender->AddMenuExtension("FileBlueprint",
			EExtensionHook::Before,
			nullptr,
			FMenuExtensionDelegate::CreateRaw(this, &FRecentBlueprintMenuModule::OnBuildBlueprintMenu));
		MenuExtender->AddExtender(BlueprintMenuExtender);
	}

	//SUBSCRIBE TO BLUEPRINT OPEN EVENTS
#if ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 24
	FAssetEditorManager::Get().OnAssetEditorRequestedOpen().AddLambda([](UObject* Asset)
#else
	GEditor->GetEditorSubsystem<UAssetEditorSubsystem>()->OnAssetEditorRequestedOpen().AddLambda([](UObject* Asset)
#endif
	{
		if (Asset && Asset->GetClass() == UBlueprint::StaticClass() && Asset->GetClass() != ULevelScriptBlueprint::StaticClass())
		{
			FRecentBlueprintMenuUtils::OnBlueprintOpened(Asset->GetPathName());				
		}
	});
}

void FRecentBlueprintMenuModule::ShutdownModule()
{
}

void FRecentBlueprintMenuModule::OnBuildBlueprintMenu(FMenuBuilder& MenuBuilder)
{
	MenuBuilder.BeginSection("RecentBlueprintMenuSection", FText::FromString("Quick Access"));
	MenuBuilder.AddSubMenu(FText::FromString("Recent Blueprints..."),
		FText::FromString("Select a Blueprint to edit from a list of recently opened ones."),
		FNewMenuDelegate::CreateRaw(this, &FRecentBlueprintMenuModule::OnBuildRecentSubMenu),
		false,
		FSlateIcon(FEditorStyle::GetStyleSetName(),"GraphEditor.Timeline_16x"));
	MenuBuilder.EndSection();		
}

void FRecentBlueprintMenuModule::OnBuildRecentSubMenu(FMenuBuilder& MenuBuilder)
{
	//purge first to ensure we have a list with no bad assets
	FRecentBlueprintMenuUtils::PurgeList();
	
	TArray<FString> RecentList = GetDefault<URecentBlueprintMenuSettings>()->RecentBlueprints;
	for (FString Entry : RecentList)
	{
		MenuBuilder.AddMenuEntry(FText::FromString(FPackageName::ObjectPathToObjectName(Entry)),
			FText::FromString(FPackageName::ObjectPathToPackageName(Entry)),
			FSlateIcon(),
			FUIAction(FExecuteAction::CreateLambda([Entry]()
			{
#if ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 24
				FAssetEditorManager::Get().OpenEditorForAsset(Entry);
#else
				GEditor->GetEditorSubsystem<UAssetEditorSubsystem>()->OpenEditorForAsset(Entry);
#endif
			})));	
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FRecentBlueprintMenuModule, RecentBlueprintMenu)