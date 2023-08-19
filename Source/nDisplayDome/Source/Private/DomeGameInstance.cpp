// Fill out your copyright notice in the Description page of Project Settings.


#include "Source/Public/DomeGameInstance.h"
#include "FileMediaSource.h"
#include "LevelSequence/Public/LevelSequencePlayer.h"
#include "LevelSequence/Public/LevelSequenceActor.h"
#include "MediaAssets/Public/MediaPlayer.h"

ADomeGameInstance::ADomeGameInstance()
{
	PrimaryActorTick.bCanEverTick = true;
}

//void YourCharacterClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//	PlayerInputComponent->BindAction("YourActionName", IE_Pressed, this, &YourCharacterClass::YourFunctionName);
//	PlayerInputComponent->BindAxis("YourAxisName", this, &YourCharacterClass::YourFunctionForAxis);
//}

void ADomeGameInstance::BeginPlay()
{
    Super::BeginPlay();
	PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
}

void ADomeGameInstance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GEngine && GEngine->GameViewport)
	{
		if (PlayerController)
		{
			const FKey Key1(EKeys::One);
			if (PlayerController->WasInputKeyJustPressed(Key1))
			{
				if (SequencePlayer)
				{
					GetWorld()->DestroyActor(OutActor);
				}

				LoadSequence(Team1);
			}
			const FKey Key2(EKeys::Two);
			if (PlayerController->WasInputKeyJustPressed(Key2))
			{
				if (SequencePlayer)
				{
					GetWorld()->DestroyActor(OutActor);
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
					GetWorld()->DestroyActor(OutActor);
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
					GetWorld()->DestroyActor(OutActor);
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
					GetWorld()->DestroyActor(OutActor);
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
			const FKey Key6(EKeys::Six);
			if (PlayerController->WasInputKeyJustPressed(Key6))
			{
				if (SequencePlayer)
				{
					GetWorld()->DestroyActor(OutActor);
				}
				MySequence = LoadObject<ULevelSequence>(nullptr, TEXT("/Game/Tests/test_stereo.test_stereo"));

				if (MySequence)
				{
					SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), MySequence, PlaybackSettings, OutActor);
					SequencePlayer->OnFinished.AddDynamic(this, &ADomeGameInstance::OnSequenceFinished);

					if (SequencePlayer)
					{
						SequencePlayer->Play();
					}
				}
			}
			const FKey Key7(EKeys::Seven);
			if (PlayerController->WasInputKeyJustPressed(Key7))
			{
				if (SequencePlayer)
				{
					GetWorld()->DestroyActor(OutActor);
				}
				MySequence = LoadObject<ULevelSequence>(nullptr, TEXT("/Game/Tests/test_shots.test_shots"));

				if (MySequence)
				{
					SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), MySequence, PlaybackSettings, OutActor);
					SequencePlayer->OnFinished.AddDynamic(this, &ADomeGameInstance::OnSequenceFinished);

					if (SequencePlayer)
					{
						SequencePlayer->Play();
					}
				}
			}
			const FKey Key8(EKeys::Eight);
			if (PlayerController->WasInputKeyJustPressed(Key8))
			{
				if (SequencePlayer)
				{
					GetWorld()->DestroyActor(OutActor);
				}
				MySequence = LoadObject<ULevelSequence>(nullptr, TEXT("/Game/Tests/new_map.new_map"));

				if (MySequence)
				{
					SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), MySequence, PlaybackSettings, OutActor);
					SequencePlayer->OnFinished.AddDynamic(this, &ADomeGameInstance::OnSequenceFinished);

					if (SequencePlayer)
					{
						SequencePlayer->Play();
					}
				}
			}
			const FKey Key9(EKeys::Nine);
			if (PlayerController->WasInputKeyJustPressed(Key9))
			{
				if (SequencePlayer)
				{
					GetWorld()->DestroyActor(OutActor);
				}
				MySequence = LoadObject<ULevelSequence>(nullptr, TEXT("/Game/Tests/test_multi_shots.test_multi_shots"));

				if (MySequence)
				{
					SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), MySequence, PlaybackSettings, OutActor);
					SequencePlayer->OnFinished.AddDynamic(this, &ADomeGameInstance::OnSequenceFinished);

					if (SequencePlayer)
					{
						SequencePlayer->Play();
					}
				}
			}
			const FKey Key0(EKeys::Zero);
			if (PlayerController->WasInputKeyJustPressed(Key0))
			{
				if (SequencePlayer)
				{
					GetWorld()->DestroyActor(OutActor);
				}
				MySequence = LoadObject<ULevelSequence>(nullptr, TEXT("/Game/Tests/test_multi_shots_main_world.test_multi_shots_main_world"));

				if (MySequence)
				{
					SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), MySequence, PlaybackSettings, OutActor);
					SequencePlayer->OnFinished.AddDynamic(this, &ADomeGameInstance::OnSequenceFinished);

					if (SequencePlayer)
					{
						SequencePlayer->Play();
					}
				}
			}
			const FKey KeyM(EKeys::M);
			if (PlayerController->WasInputKeyJustPressed(KeyM))
			{
				UGameplayStatics::OpenLevel(this, FName("/Game/Venice_fast_building/Maps/Showcase"), true);
			}
			const FKey KeyN(EKeys::N);
			if (PlayerController->WasInputKeyJustPressed(KeyN))
			{
				UGameplayStatics::OpenLevel(this, FName("/Game/World/Maps/World"), true);
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
			const FKey KeyK(EKeys::K);
			if (PlayerController->WasInputKeyJustPressed(KeyK))
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

void ADomeGameInstance::LoadSequence(FString TeamSeq) 
{
	PlaybackSettings.bDisableCameraCuts = false;
	MySequence = LoadObject<ULevelSequence>(nullptr, TEXT("/Game/Team1/Seq/Team1.Team1"));

	if (MySequence)
	{
		SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), MySequence, PlaybackSettings, OutActor);
		SequencePlayer->OnFinished.AddDynamic(this, &ADomeGameInstance::OnSequenceFinished);

		if (SequencePlayer)
		{
			SequencePlayer->Play();
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