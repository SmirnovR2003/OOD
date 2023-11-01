#pragma once
#include "CConstDocumentItem.h"

/*
������� ���������. ��������� �������� ������ � ����������� ��� ���������
*/
class CDocumentItem : public CConstDocumentItem
{
public:
	CDocumentItem(std::shared_ptr<IImage> image)
		:m_item({ image , std::nullopt})
		, m_itemType(ItemType::Image)
	{
	}
	CDocumentItem(std::shared_ptr<IParagraph> paragraph)
		:m_item({std::nullopt,paragraph })
		, m_itemType(ItemType::Paragraph)
	{
	}
	// ���������� ��������� �� �����������, ���� nullptr,
	// ���� ������� �� �������� ������������
	std::shared_ptr<IImage> GetImage()const
	{
		if (m_itemType == ItemType::Image && m_item.first.has_value())
		{
			return m_item.first.value();
		}
		else
		{
			return nullptr;
		}
	};

	// ���������� ��������� �� ��������, ���� nullptr, ���� ������� �� �������� ����������
	std::shared_ptr<IParagraph> GetParagraph()const
	{
		if (m_itemType == ItemType::Paragraph && m_item.second.has_value())
		{
			return m_item.second.value();
		}
		else
		{
			return nullptr;
		}
	};

	ItemType GetType() const
	{
		return m_itemType;
	}


	std::string GetItemInfo() const
	{
		if (m_itemType == ItemType::Paragraph && m_item.second.has_value())
		{
			return m_item.second.value()->GetInfo();
		}
		else
		{
			return m_item.first.value()->GetInfo();
		}

	}

private:
	std::pair<std::optional<std::shared_ptr<IImage>>, std::optional<std::shared_ptr<IParagraph>>> m_item;
	ItemType m_itemType;
};

