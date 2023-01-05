// Copyright 2023 Nino Saglia & Tim Verberne

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ProjectileData.generated.h"

/** Data asset for projectiles. */
UCLASS(BlueprintType)
class UProjectileData : public UDataAsset
{
	GENERATED_BODY()

public:


	/** Projectile Description. Is for documentation purposes only. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Description)
	FText Description;

	/** When set to enabled, this projectile will explode on impact with a surface. Explosive projectiles cannot bounce on surfaces.
	 *  Enable this for high explosive shells or grenades. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Type, meta = (DisplayName="Explosive"))
	bool IsExplosive {false};

	/** When set to enabled, this projectile has a fuse that will cause the projectile to detonate after a set amount of time.
	 *  This will automatically assume that the projectile is explosive. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Type, meta = (DisplayName="Timed Fuse"))
	bool IsFusedExplosive {false};

	/** Defines the projectile diameter in mm. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Projectile, meta = (DisplayName="Diameter"))
	int ProjectileDiameter {100};

	/** Defines the muzzle velocity of the projectile. A higher value will mean that the projectile leaves the barrel of the gun at a higher speed.
	 *  A good starting value is 250. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Projectile, meta = (DisplayName="Muzzle Velocity", ClampMin = 0.0, ClampMax = 1000.0, UIMin = 0.0, UIMax = 1000.0))
	float MuzzleVelocity {250.0};

	/** Defines the accuracy of the projectile. A lower value will introduce more spread to the firing pattern.
	 *  A good starting value is 95. */
	 UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Projectile, meta = (DisplayName=" Accuracy", ClampMin = 0.0, ClampMax = 1000.0, UIMin = 0.0, UIMax = 100.0))
	float Accuracy {98.0};
};
