// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GEOMETRYSANDBOX_GeometryHubActor_generated_h
#error "GeometryHubActor.generated.h already included, missing '#pragma once' in GeometryHubActor.h"
#endif
#define GEOMETRYSANDBOX_GeometryHubActor_generated_h

#define GeometrySandbox_Source_GeometrySandbox_Public_GeometryHubActor_h_12_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FGeometrySpawnData_Statics; \
	GEOMETRYSANDBOX_API static class UScriptStruct* StaticStruct();


template<> GEOMETRYSANDBOX_API UScriptStruct* StaticStruct<struct FGeometrySpawnData>();

#define GeometrySandbox_Source_GeometrySandbox_Public_GeometryHubActor_h_30_SPARSE_DATA
#define GeometrySandbox_Source_GeometrySandbox_Public_GeometryHubActor_h_30_RPC_WRAPPERS
#define GeometrySandbox_Source_GeometrySandbox_Public_GeometryHubActor_h_30_RPC_WRAPPERS_NO_PURE_DECLS
#define GeometrySandbox_Source_GeometrySandbox_Public_GeometryHubActor_h_30_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGeometryHubActor(); \
	friend struct Z_Construct_UClass_AGeometryHubActor_Statics; \
public: \
	DECLARE_CLASS(AGeometryHubActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GeometrySandbox"), NO_API) \
	DECLARE_SERIALIZER(AGeometryHubActor)


#define GeometrySandbox_Source_GeometrySandbox_Public_GeometryHubActor_h_30_INCLASS \
private: \
	static void StaticRegisterNativesAGeometryHubActor(); \
	friend struct Z_Construct_UClass_AGeometryHubActor_Statics; \
public: \
	DECLARE_CLASS(AGeometryHubActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GeometrySandbox"), NO_API) \
	DECLARE_SERIALIZER(AGeometryHubActor)


#define GeometrySandbox_Source_GeometrySandbox_Public_GeometryHubActor_h_30_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGeometryHubActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGeometryHubActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGeometryHubActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGeometryHubActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGeometryHubActor(AGeometryHubActor&&); \
	NO_API AGeometryHubActor(const AGeometryHubActor&); \
public:


#define GeometrySandbox_Source_GeometrySandbox_Public_GeometryHubActor_h_30_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGeometryHubActor(AGeometryHubActor&&); \
	NO_API AGeometryHubActor(const AGeometryHubActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGeometryHubActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGeometryHubActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGeometryHubActor)


#define GeometrySandbox_Source_GeometrySandbox_Public_GeometryHubActor_h_30_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__GeometryActor() { return STRUCT_OFFSET(AGeometryHubActor, GeometryActor); } \
	FORCEINLINE static uint32 __PPO__Class() { return STRUCT_OFFSET(AGeometryHubActor, Class); } \
	FORCEINLINE static uint32 __PPO__GeometryObject() { return STRUCT_OFFSET(AGeometryHubActor, GeometryObject); } \
	FORCEINLINE static uint32 __PPO__SpawnDatas() { return STRUCT_OFFSET(AGeometryHubActor, SpawnDatas); }


#define GeometrySandbox_Source_GeometrySandbox_Public_GeometryHubActor_h_27_PROLOG
#define GeometrySandbox_Source_GeometrySandbox_Public_GeometryHubActor_h_30_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GeometrySandbox_Source_GeometrySandbox_Public_GeometryHubActor_h_30_PRIVATE_PROPERTY_OFFSET \
	GeometrySandbox_Source_GeometrySandbox_Public_GeometryHubActor_h_30_SPARSE_DATA \
	GeometrySandbox_Source_GeometrySandbox_Public_GeometryHubActor_h_30_RPC_WRAPPERS \
	GeometrySandbox_Source_GeometrySandbox_Public_GeometryHubActor_h_30_INCLASS \
	GeometrySandbox_Source_GeometrySandbox_Public_GeometryHubActor_h_30_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GeometrySandbox_Source_GeometrySandbox_Public_GeometryHubActor_h_30_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GeometrySandbox_Source_GeometrySandbox_Public_GeometryHubActor_h_30_PRIVATE_PROPERTY_OFFSET \
	GeometrySandbox_Source_GeometrySandbox_Public_GeometryHubActor_h_30_SPARSE_DATA \
	GeometrySandbox_Source_GeometrySandbox_Public_GeometryHubActor_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
	GeometrySandbox_Source_GeometrySandbox_Public_GeometryHubActor_h_30_INCLASS_NO_PURE_DECLS \
	GeometrySandbox_Source_GeometrySandbox_Public_GeometryHubActor_h_30_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GEOMETRYSANDBOX_API UClass* StaticClass<class AGeometryHubActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GeometrySandbox_Source_GeometrySandbox_Public_GeometryHubActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
