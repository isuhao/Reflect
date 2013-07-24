#include "Reflect/TranslatorDeduction.h"
#include "Reflect/Object.h"

#if !HELIUM_RELEASE

namespace Helium
{
	namespace Reflect
	{
		struct TestEnumeration : Enum
		{
			enum Enum
			{
				ValueOne,
				ValueTwo,
			};

			REFLECT_DECLARE_ENUM( TestEnumeration );
			static void PopulateMetaType( MetaEnum& info );
		};

		struct TestStructure : Struct
		{
			uint8_t  m_Uint8;
			uint16_t m_Uint16;
			uint32_t m_Uint32;
			uint64_t m_Uint64;

			int8_t  m_Int8;
			int16_t m_Int16;
			int32_t m_Int32;
			int64_t m_Int64;

			float32_t m_Float32;
			float64_t m_Float64;

			std::vector<uint32_t> m_StdVectorUint32;
			std::set<uint32_t> m_StdSetUint32;
			std::map<uint32_t, uint32_t> m_StdMapUint32;
	
			DynamicArray<uint32_t> m_FoundationDynamicArrayUint32;
			Set<uint32_t> m_FoundationSetUint32;
			Map<uint32_t, uint32_t> m_FoundationMapUint32;

			REFLECT_DECLARE_BASE_STRUCT( TestStructure );
			static void PopulateMetaType( MetaStruct& comp );
		};

		class TestObject : public Object
		{
			TestStructure m_Struct;
			TestStructure m_StructArray[ 8 ];

			TestEnumeration m_Enumeration;
			TestEnumeration m_EnumerationArray[ 8 ];

			REFLECT_DECLARE_CLASS( TestObject, Object );
			static void PopulateMetaType( MetaClass& comp );
		};

		void RunTests();
	}
}

#endif