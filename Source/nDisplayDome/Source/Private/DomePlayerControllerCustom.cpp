// Fill out your copyright notice in the Description page of Project Settings.


#include "Source/Public/DomePlayerControllerCustom.h"
#include "FileMediaSource.h"
#include "LevelSequence/Public/LevelSequencePlayer.h"
#include "LevelSequence/Public/LevelSequenceActor.h"
#include "MediaAssets/Public/MediaPlayer.h"

ADomePlayerControllerCustom::ADomePlayerControllerCustom()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ADomePlayerControllerCustom::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction<SequenceName>("Input_One", IE_Released, this, &ADomePlayerControllerCustom::LoadSequence, Team1);
	InputComponent->BindAction<SequenceName>("Input_Two", IE_Released, this, &ADomePlayerControllerCustom::LoadSequence, Team2);
	InputComponent->BindAction<SequenceName>("Input_Three", IE_Released, this, &ADomePlayerControllerCustom::LoadSequence, Team3);
	InputComponent->BindAction<SequenceName>("Input_Four", IE_Released, this, &ADomePlayerControllerCustom::LoadSequence, Team4);
	InputComponent->BindAction("PlayPauseSequence", IE_Released, this, &ADomePlayerControllerCustom::PlayPauseSequence);
	InputComponent->BindAction("ClearSequence", IE_Released, this, &ADomePlayerControllerCustom::ClearSequence);

	InputComponent->BindAction<SequenceName>("Input_Five", IE_Released, this, &ADomePlayerControllerCustom::LoadSequence, Test1);
	
}

void ADomePlayerControllerCustom::BeginPlay()
{
    Super::BeginPlay();
	PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
}

void ADomePlayerControllerCustom::LoadSequence(FString TeamSeq) 
{
	PlaybackSettings.bDisableCameraCuts = false;

	ClearSequence();
	
	MySequence = LoadObject<ULevelSequence>(nullptr, *TeamSeq);

	if (MySequence)
	{
		SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), MySequence, PlaybackSettings, OutActor);
		SequencePlayer->OnFinished.AddDynamic(this, &ADomePlayerControllerCustom::OnSequenceFinished);

		if (SequencePlayer)
		{
			SequencePlayer->Play();
		}
	}
}

void ADomePlayerControllerCustom::PlayPauseSequence()
{
	if (SequencePlayer)
	{
		if (SequencePlayer->IsPlaying())
		{
			SequencePlayer->Pause();
			return;
		}

		if (SequencePlayer->IsPaused())
		{
			SequencePlayer->Play();
			return;
		}
	}
}

void ADomePlayerControllerCustom::ClearSequence()
{
	if (SequencePlayer)
	{
		GetWorld()->DestroyActor(OutActor);
	}
}

void ADomePlayerControllerCustom::OnSequenceFinished()
{
	UE_LOG(LogTemp, Warning, TEXT("Sequence has finished!"));
	SequencePlayer->OnFinished.RemoveDynamic(this, &ADomePlayerControllerCustom::OnSequenceFinished);
	// SequencePlayer->Pause();
	// SequencePlayer = nullptr;
	// APlayerController* PC = GetWorld()->GetFirstPlayerController();
	// PC->SetViewTarget(PC->GetPawn());
}