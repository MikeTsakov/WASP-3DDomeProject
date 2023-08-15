// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "Cameras.generated.h"

UCLASS()
class NDISPLAYDOME_API ACameras : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameras();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Initialize();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	TArray<ACameraActor*> FoundCameras;
};
