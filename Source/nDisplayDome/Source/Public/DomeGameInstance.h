// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelSequence.h"
#include "LevelSequencePlayer.h"
#include "DomeGameInstance.generated.h"

class ALevelSequenceActor;

UCLASS()
class NDISPLAYDOME_API ADomeGameInstance : public AActor
{
	GENERATED_BODY()

public:	
	ADomeGameInstance();
	
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime);
    virtual bool IsTickable() const { return true; }
    virtual TStatId GetStatId() const; 

private:
	UFUNCTION()
	void OnSequenceFinished();
	
	UPROPERTY()
	ULevelSequence* MySequence;

	UPROPERTY()
	ULevelSequencePlayer* SequencePlayer {};

	UPROPERTY()
	ALevelSequenceActor* OutActor {};

};
	
