#pragma once

#include <memory>
#include "IImage.h"
#include "IParagraph.h"
#include <optional>
#include <stdexcept>
/*
Неизменяемый элемент документа
*/

enum class ItemType
{
	Image = 0,
	Paragraph,
};

class CConstDocumentItem
{
public:
	// Возвращает указатель на константное изображение, либо nullptr,
    // если элемент не является изображением
	const std::shared_ptr<IImage> GetImage()const
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

	// Возвращает указатель на константный параграф, либо nullptr, если элемент не является параграфом
	const std::shared_ptr<IParagraph> GetParagraph()const
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

	virtual ~CConstDocumentItem() = default;
private:
	std::pair<std::optional<std::shared_ptr<IImage>>, std::optional<std::shared_ptr<IParagraph>>> m_item;
	ItemType m_itemType;
};

