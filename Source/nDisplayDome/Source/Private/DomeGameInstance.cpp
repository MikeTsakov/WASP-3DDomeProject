// Fill out your copyright notice in the Description page of Project Settings.


#include "Source/Public/DomeGameInstance.h"
#include "FileMediaSource.h"
#include "MovieSceneSequencePlayer.h"
#include "LevelSequence/Public/LevelSequencePlayer.h"
#include "LevelSequence/Public/LevelSequenceActor.h"
#include "MediaAssets/Public/MediaPlayer.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

ADomeGameInstance::ADomeGameInstance()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ADomeGameInstance::BeginPlay()
{
    Super::BeginPlay();
}

void ADomeGameInstance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GEngine && GEngine->GameViewport)
	{
		APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		FMovieSceneSequencePlaybackSettings PlaybackSettings;
		PlaybackSettings.bDisableCameraCuts = false;
		if (PlayerController)
		{
			const FKey Key1(EKeys::One);
			if (PlayerController->WasInputKeyJustPressed(Key1))
			{
				if (SequencePlayer)
				{
					if (SequencePlayer->IsPlaying())
					{
						SequencePlayer->Pause();
						GetWorld()->DestroyActor(OutActor);
					}
				}
				MySequence = LoadObject<ULevelSequence>(nullptr, TEXT("/Game/Team1/Seq/Team1.Team1"));
				
				if(MySequence)
				{
					SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), MySequence, PlaybackSettings, OutActor);
					SequencePlayer->OnFinished.AddDynamic(this, &ADomeGameInstance::OnSequenceFinished);
					
					if (SequencePlayer)
					{
						SequencePlayer->Play();
					}
				}
			}
			const FKey Key2(EKeys::Two);
			if (PlayerController->WasInputKeyJustPressed(Key2))
			{
				if (SequencePlayer)
				{
					if (SequencePlayer->IsPlaying())
					{
						SequencePlayer->Pause();
						GetWorld()->DestroyActor(OutActor);
					}
				}
				MySequence = LoadObject<ULevelSequence>(nullptr, TEXT("/Game/Team2/Seq/Team2.Team2"));
				
				if(MySequence)
				{
					SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), MySequence, PlaybackSettings, OutActor);
					SequencePlayer->OnFinished.AddDynamic(this, &ADomeGameInstance::OnSequenceFinished);
					
					if (SequencePlayer)
					{
						SequencePlayer->Play();
					}
				}
			}
			const FKey Key3(EKeys::Three);
			if (PlayerController->WasInputKeyJustPressed(Key3))
			{
				if (SequencePlayer)
				{
					if (SequencePlayer->IsPlaying())
					{
						SequencePlayer->Pause();
						GetWorld()->DestroyActor(OutActor);
					}
				}
				MySequence = LoadObject<ULevelSequence>(nullptr, TEXT("/Game/Team3/Seq/Team3.Team3"));
				
				if(MySequence)
				{
					SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), MySequence, PlaybackSettings, OutActor);
					SequencePlayer->OnFinished.AddDynamic(this, &ADomeGameInstance::OnSequenceFinished);
					
					if (SequencePlayer)
					{
						SequencePlayer->Play();
					}
				}
			}
			const FKey Key4(EKeys::Four);
			if (PlayerController->WasInputKeyJustPressed(Key4))
			{
				if (SequencePlayer)
				{
					if (SequencePlayer->IsPlaying())
					{
						SequencePlayer->Pause();
						GetWorld()->DestroyActor(OutActor);
					}
				}
				MySequence = LoadObject<ULevelSequence>(nullptr, TEXT("/Game/Team4_Enigma/Seq/Team4.Team4"));
				
				if(MySequence)
				{
					SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), MySequence, PlaybackSettings, OutActor);
					SequencePlayer->OnFinished.AddDynamic(this, &ADomeGameInstance::OnSequenceFinished);
					
					if (SequencePlayer)
					{
						SequencePlayer->Play();
					}
				}
			}
			const FKey Key5(EKeys::Five);
			if (PlayerController->WasInputKeyJustPressed(Key5))
			{
				if (SequencePlayer)
				{
					if (SequencePlayer->IsPlaying())
					{
						SequencePlayer->Pause();
						GetWorld()->DestroyActor(OutActor);
					}
				}
				MySequence = LoadObject<ULevelSequence>(nullptr, TEXT("/Game/Tests/testinng.testinng"));
				
				if(MySequence)
				{
					SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), MySequence, PlaybackSettings, OutActor);
					SequencePlayer->OnFinished.AddDynamic(this, &ADomeGameInstance::OnSequenceFinished);
					
					if (SequencePlayer)
					{
						SequencePlayer->Play();
					}
				}
			}
			const FKey KeyP(EKeys::P);
			if (PlayerController->WasInputKeyJustPressed(KeyP))
			{
				SequencePlayer->Pause();
			}
			const FKey KeyO(EKeys::O);
			if (PlayerController->WasInputKeyJustPressed(KeyO))
			{
				SequencePlayer->Play();
			}
			const FKey KeyClose(EKeys::LeftBracket);
			if (PlayerController->WasInputKeyJustPressed(KeyClose))
			{
				if (SequencePlayer)
				{
					SequencePlayer->Pause();
					GetWorld()->DestroyActor(OutActor);
//					APlayerController* PC = GetWorld()->GetFirstPlayerController();
//					PC->SetViewTarget(PC->GetPawn());
				}
			}
		}
	}
}

void ADomeGameInstance::OnSequenceFinished()
{
	UE_LOG(LogTemp, Warning, TEXT("Sequence has finished!"));
	SequencePlayer->OnFinished.RemoveDynamic(this, &ADomeGameInstance::OnSequenceFinished);
	// SequencePlayer->Pause();
	// SequencePlayer = nullptr;
	// APlayerController* PC = GetWorld()->GetFirstPlayerController();
	// PC->SetViewTarget(PC->GetPawn());
}

TStatId ADomeGameInstance::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(ADomeGameInstance, STATGROUP_Tickables);
}