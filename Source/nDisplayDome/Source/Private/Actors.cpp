// Fill out your copyright notice in the Description page of Project Settings.

#include "Source/Public/Actors.h"

#include "EngineUtils.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AActors::AActors()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	// RootComponent = Mesh;
	// Mesh->bUseAsyncCooking = true;
}

// Called when the game starts or when spawned
void AActors::BeginPlay()
{
	Super::BeginPlay();
	Initialize();
}

// Called every frame
void AActors::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// TODO: Based on input from the keyboard, read specific config file and load it's data
	// Use Initialize() to setup generic components, meshes, location, cameras
	// Use SetupConfig() to read the config.
	// Use SetupCinematic() to apply animations
	// Use PlayCinematic() to play the final version
	// if (!FMemory::Memcmp(&MyStructData, &LastKnownStructData, sizeof(FActorData)))
	// {
	// 	// The struct has changed
	// 	OnMyStructChanged.Broadcast(MyStructData);
	// 	LastKnownStructData = MyStructData;  // Update our last known struct data
	// }
}

void AActors::Initialize()
{

	// Read config files one by one
	// 

	UWorld* World = GetWorld();  // Get reference to the game world
    if(World)
    {
    	//
        // Replace with your tags and corresponding mesh paths
        TMap<FString, FString> TagToMeshPathMap = {
            // {"LaForgeMale", "/Game/Characters/LaForge/Male/LaForgeMale"},
            {"LaForgeMale", "/Game/Team1/Lea/Lea_merged"},
            {"LaForgeFemale", "/Game/Characters/LaForge/Female/LaForgeFemale"},
            // Add as many tags and mesh paths as you need Team1/Lea
        };

        for (TActorIterator<AActor> It(World); It; ++It)
        {
            // Get the actor's tags
            const TArray<FName>& ActorTags = It->Tags;

            // Iterate over each tag in the actor
            for (const FName& ActorTag : ActorTags)
            {
                FString ActorTagString = ActorTag.ToString();
                // Check if this tag is in the map
                if (TagToMeshPathMap.Contains(ActorTagString))
                {
                	FActorData ActorData = MakeShared<FActorData>().Get();
                    // Save the location, rotation, etc.
                    ActorData.ActorLocation = It->GetActorLocation();
                    ActorData.ActorRotation = It->GetActorRotation();
                	ActorData.ActorTransform = It->GetTransform();

                	// Destroy the old actor
                    It->Destroy();

                    // Spawn a new actor with the mesh associated with this tag
                    USkeletalMesh* NewMesh = LoadObject<USkeletalMesh>(NULL, *TagToMeshPathMap[ActorTagString]);

                    if (NewMesh)
                    {
                        // Create an actor with the new mesh
                        AActor* NewActor = World->SpawnActor<AActor>(AActor::StaticClass(), ActorData.ActorLocation, ActorData.ActorRotation);

                    	ActorData.ActorObject = NewActor;
                    	// Cannot set this because the mesh does not fit the skeleton
                    	// Needs to be retargeted
                        SkeletalMeshComponent = NewObject<USkeletalMeshComponent>(NewActor);
                        SkeletalMeshComponent->SetSkeletalMesh(NewMesh);
                        NewActor->SetRootComponent(SkeletalMeshComponent);
                        NewActor->AddInstanceComponent(SkeletalMeshComponent);
                        SkeletalMeshComponent->RegisterComponent();

                    	NewActor->SetActorLocation(ActorData.ActorLocation);
                    	NewActor->SetActorRotation(ActorData.ActorRotation);

                    	// Load and play an animation
                    	UAnimSequence* Animation = LoadObject<UAnimSequence>(NULL, TEXT("/Game/Team1/Lea/Lea_merged_Anim_00003_Lea_3"));
                    	if (Animation)
                    	{
                    		// Is not applied because the skeleton is not set
                    		SkeletalMeshComponent->PlayAnimation(Animation, true);
                    	}
                    }

                    break;
                }
            }
        }
    }
}

FTransform AActors::GetTransform()
{
	return CharacterTransform;
}

void AActors::SetTransform(const FTransform* NewTransform)
{
	CharacterTransform = *NewTransform;
}
