#pragma once
#include <span>
#include <ranges>
#include <vector>
#include <Zut/ZxStr.h>
#include <Zut/ZxMem.h>
#include <Zut/ZxJson.h>

#include <Revne/RxQLIE/Cryptor.h>


namespace Zqf::Revne::QLIE
{
	class ABMPLayer
	{
	private:

	};


	class ABMPMotion
	{
	private:
		std::vector<ABMPLayer> m_vcData;
	};


	class ABMPData15
	{
	private:
		size_t m_nVersion{};
		Zut::ZxMem m_zmData;

	public:
		ABMPData15();
		ABMPData15(Zut::ZxMem& zmReader);

	public:
		auto Load(Zut::ZxMem& zmReader) -> void;
		auto Load(const std::string_view msDir, Zut::ZxJson::JObject_t& rfJObject) -> void;
		auto Save(const std::string_view msSaveDir) const->Zut::ZxJson::JObject_t;
		auto Make(Zut::ZxMem& zmWriter) const -> void;

	public:
		auto SizeBytes() const->size_t;
	};
}

namespace Zqf::Revne::QLIE
{
	enum class ABMPImageDataType : uint8_t
	{
		BMP = 0, // .bmp
		JPG = 1, // .jpg
		PNG0 = 2, // .png
		PNG1 = 3, // .png
		M = 4, // .m
		ARGB = 5, // .argb
		B = 6, // .b
		OGV = 7, // .ogg
		MDL = 8 // .mdl
	};


	class ABMPImageData15
	{
	private:
		size_t m_nVirtualFlag{};
		std::u16string m_u16FileName;
		std::string m_msHashName;
		ABMPImageDataType m_eType{};
		size_t m_nOffsetX{};
		size_t m_nOffsetY{};
		size_t m_nOffsetZ{};
		size_t m_nVirtualWidth{};
		size_t m_nVirtualHeigh{};
		size_t m_nVirtualDepth{};
		size_t m_nRenderingTextureMode{};
		size_t m_nRenderingTextureBGColor{};
		Zut::ZxMem m_zmData;

	public:
		ABMPImageData15();
		ABMPImageData15(Zut::ZxMem& zmReader);
		ABMPImageData15(const std::string_view msDir, Zut::ZxJson::JObject_t& rfJObject);

	public:
		auto Load(Zut::ZxMem& zmReader) -> void;
		auto Load(const std::string_view msDir, Zut::ZxJson::JObject_t& rfJObject) -> void;
		auto Save(const std::string_view msSaveDir) const->Zut::ZxJson::JObject_t;
		auto Make(Zut::ZxMem& zmWriter) const -> void;

	public:
		auto SizeBytes() const->size_t;
		auto GetSuffix() const->std::string_view;
	};


	class ABMPImage10
	{
	private:
		std::vector<ABMPImageData15> m_vcData;

	public:
		ABMPImage10();
		ABMPImage10(Zut::ZxMem& zmReader);

	public:
		auto Load(Zut::ZxMem& zmReader) -> void;
		auto Load(const std::string_view msDir, Zut::ZxJson::JObject_t& rfJObject) -> void;
		auto Save(const std::string_view msSaveDir) const->Zut::ZxJson::JObject_t;
		auto Make(Zut::ZxMem& zmWriter) const -> void;

	public:
		auto SizeBytes() const->size_t;
	};
}

namespace Zqf::Revne::QLIE
{
	enum class ABMPSoundDataType : uint8_t
	{
		WAV = 0,
		OGG = 1
	};


	class ABMPSoundData12
	{
	private:
		size_t m_nFlag{};
		std::u16string m_u16FileName;
		std::string m_msHashName;
		ABMPSoundDataType m_eType{};
		Zut::ZxMem m_zmData;

	public:
		ABMPSoundData12();
		ABMPSoundData12(Zut::ZxMem& zmReader);
		ABMPSoundData12(const std::string_view msDir, Zut::ZxJson::JObject_t& rfJObject);

	public:
		auto Load(Zut::ZxMem& zmReader) -> void;
		auto Load(const std::string_view msDir, Zut::ZxJson::JObject_t& rfJObject) -> void;
		auto Save(const std::string_view msSaveDir) const->Zut::ZxJson::JObject_t;
		auto Make(Zut::ZxMem& zmWriter) const -> void;

	public:
		auto SizeBytes() const->size_t;
		auto GetSuffix() const->std::string_view;
	};


	class ABMPSound10
	{
	private:
		std::vector<ABMPSoundData12> m_vcData;

	public:
		ABMPSound10();
		ABMPSound10(Zut::ZxMem& zmReader);

	public:
		auto Load(Zut::ZxMem& zmReader) -> void;
		auto Load(const std::string_view msDir, Zut::ZxJson::JObject_t& rfJObject) -> void;
		auto Save(const std::string_view msSaveDir) const->Zut::ZxJson::JObject_t;
		auto Make(Zut::ZxMem& zmWriter) const -> void;

	public:
		auto SizeBytes() const->size_t;
	};
}

namespace Zqf::Revne::QLIE
{
	class AnimationBMP12
	{
	private:
		ABMPData15 m_ABData;
		ABMPImage10 m_ABImage;
		ABMPSound10 m_ABSound;

	public:
		AnimationBMP12();
		AnimationBMP12(Zut::ZxMem& zmReader);
		AnimationBMP12(const std::string_view msDir);

	public:
		auto Load(Zut::ZxMem& zmReader) -> void;
		auto Load(const std::string_view msDir) -> void;
		auto Save(const std::string_view msSaveDir) -> void;
		auto Make(const std::string_view msMakePath) -> void;
	};
}