// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelSequence.h"
#include "LevelSequencePlayer.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "MovieSceneSequencePlayer.h"
#include "InputCoreTypes.h"
#include "DomeGameInstance.generated.h"

class ALevelSequenceActor;

UCLASS()
class NDISPLAYDOME_API ADomeGameInstance : public AActor
{
	GENERATED_BODY()

public:	

	APlayerController* PlayerController;
	FMovieSceneSequencePlaybackSettings PlaybackSettings {};

	ADomeGameInstance();
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime);
    virtual bool IsTickable() const { return true; }
    virtual TStatId GetStatId() const; 
	void LoadSequence(FString TeamSeq);

private:
	UFUNCTION()
	void OnSequenceFinished();
	
	UPROPERTY()
	ULevelSequence* MySequence;

	UPROPERTY()
	ULevelSequencePlayer* SequencePlayer {};

	UPROPERTY()
	ALevelSequenceActor* OutActor {};

	FString Team1 = TEXT("/Game/Team1/Sequence/Team1.Team1");
	FString Team2 = TEXT("/Game/Team2/Sequence/Team2.Team2");
	FString Team3 = TEXT("/Game/Team3/Sequence/Team3.Team3");
	FString Team4 = TEXT("/Game/Team4/Sequence/Team4.Team4");
};
	
