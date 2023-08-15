// Fill out your copyright notice in the Description page of Project Settings.

#include "Source/Public/Cameras.h"

#include "Engine/Public/EngineUtils.h"
#include "Camera/CameraActor.h"

// Sets default values
ACameras::ACameras()
{
 	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACameras::BeginPlay()
{
	Super::BeginPlay();
	Initialize();
}

// Called every frame
void ACameras::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACameras::Initialize()
{

	// Read config files one by one
	// 

	UWorld* World = GetWorld();  // Get reference to the game world
    if(World)
    {
        // Replace with your tags and corresponding mesh paths
        TArray<FString> CameraTags = {
        	"CampfireCamera1",
        	"CampfireCamera2",
		};

        for (TActorIterator<ACameraActor> It(World); It; ++It)
        {
            // Get the actor's tags
            const TArray<FName>& ActorTags = It->Tags;

            // Iterate over each tag in the actor
            for (const FName& ActorTag : ActorTags)
            {
                FString ActorTagString = ActorTag.ToString();
                // Check if this tag is in the map
                if (CameraTags.Contains(ActorTagString))
                {
                    // Save the location, rotation, etc.
                    FVector Location = It->GetActorLocation();
                    FRotator Rotation = It->GetActorRotation();

                    // Destroy the old actor
                    It->Destroy();

                	FoundCameras.Add(*It);
                	
                    break;
                }
            }
        }
    }
}