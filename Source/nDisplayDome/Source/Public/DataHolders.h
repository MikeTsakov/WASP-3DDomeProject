// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataHolders.generated.h"

USTRUCT(BlueprintType)
struct FActorData
{
	GENERATED_BODY()

	FName ActorTag;
	FVector ActorLocation;
	FRotator ActorRotation;
	FTransform ActorTransform;

	UPROPERTY()
	AActor* ActorObject;
	
	UPROPERTY()
	USkeletalMesh* ActorMesh;
	
	UPROPERTY()
	USkeletalMeshComponent* ActorMeshComponent;
};

USTRUCT(BlueprintType)
struct FCameraData
{
	GENERATED_BODY()

	FName CameraTag;
	FVector CameraLocation;
	FRotator CameraRotator;
	FTransform CameraTransform;

	UPROPERTY()
	ACameraActor* CameraObject;
	
	UPROPERTY()
	USceneCaptureComponent2D* CameraScene;
};