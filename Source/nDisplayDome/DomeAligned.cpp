// Fill out your copyright notice in the Description page of Project Settings.


#include "DomeAligned.h"

// Sets default values
ADomeAligned::ADomeAligned()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADomeAligned::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADomeAligned::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//In order to align the Actor to the gridlines in the dome, this latitude-correction can be made:
	FVector2D LatCorr = FVector2D(LatLon.X + (PI / 2.0), LatLon.Y);
	FVector SphereLocation = LatCorr.SphericalToUnitCartesian();
	SetActorLocation(DomeOrigin + SphereLocation * DomeRadius);
}

