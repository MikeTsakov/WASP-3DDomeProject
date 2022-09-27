// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DomeAligned.generated.h"

UCLASS()
class NDISPLAYDOME_API ADomeAligned : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADomeAligned();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FVector DomeOrigin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float DomeRadius = 740;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector2D LatLon = { 0.f, 0.f };

};
