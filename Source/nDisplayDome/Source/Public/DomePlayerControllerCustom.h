// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelSequence.h"
#include "LevelSequencePlayer.h"
#include "MovieSceneSequencePlayer.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Source/Public/DataHolders.h"
#include "DomePlayerControllerCustom.generated.h"

class ALevelSequenceActor;

DECLARE_DELEGATE_OneParam( SequenceName, FString )

UCLASS()
class NDISPLAYDOME_API ADomePlayerControllerCustom : public APlayerController
{
	GENERATED_BODY()

public:
	SequenceName SequenceTeamName;
	
	UPROPERTY()
	APlayerController* PlayerController;

	UPROPERTY()
	FMovieSceneSequencePlaybackSettings PlaybackSettings {};

	// Sets default values for this actor's properties
	ADomePlayerControllerCustom();
	
	// ~Overrides: APlayerController
	virtual void SetupInputComponent() override;

	UFUNCTION()
	void LoadSequence(FString TeamSeq);

	UFUNCTION()
	void PlayPauseSequence();

	UFUNCTION()
	void ClearSequence();

private:
	FString Team1 = TEXT("/Game/Team1/Sequence/Team1.Team1");
	FString Team2 = TEXT("/Game/Team2/Sequence/Team2.Team2");
	FString Team3 = TEXT("/Game/Team3/Sequence/Team3.Team3");
	FString Team4 = TEXT("/Game/Team4/Sequence/Team4.Team4");

	FString Test1 =  TEXT("/Game/Tests/Asian_map.Asian_map");
	FString Test2 =  TEXT("/Game/Tests/test_multi_shots.test_multi_shots");
	
	UPROPERTY()
	ULevelSequence* MySequence;

	UPROPERTY()
	ULevelSequencePlayer* SequencePlayer {};

	UPROPERTY()
	ALevelSequenceActor* OutActor {};
	
	UFUNCTION()
	void OnSequenceFinished();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};