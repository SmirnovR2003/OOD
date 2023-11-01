#include <iostream>
#include "CMenu.h"
#include "CDocument.h"
#include "CExitMenuCommand.h"
#include "CMenuDeleteItemCommand.h"
#include "CMenuHelpCommand.h"
#include "CMenuInsertImageCommand.h"
#include "CMenuInsertParagraphCommand.h"
#include "CMenuListCommand.h"
#include "CMenuRedoCommand.h"
#include "CMenuReplaceTextCommand.h"
#include "CMenuResizeImageCommand.h"
#include "CMenuSaveCommand.h"
#include "CMenuSetTitleCommand.h"
#include "CMenuUndoCommand.h"

using namespace std;

int main()
{
    CDocument document;
    CMenu menu;

    menu.AddItem("exit", "Exit", make_unique<CExitMenuCommand>(menu));
    menu.AddItem("DeleteItem", "<position>", make_unique<CMenuDeleteItemCommand>(document));
    menu.AddItem("Help", "Help", make_unique<CMenuHelpCommand>(menu));
    menu.AddItem("InsertImage", "<position>|end <width> <height> <path>", make_unique<CMenuInsertImageCommand>(document));
    menu.AddItem("InsertParagraph", "<position>|end <text>", make_unique<CMenuInsertParagraphCommand>(document));
    menu.AddItem("List", "List", make_unique<CMenuListCommand>(document));
    menu.AddItem("Redo", "Redo", make_unique<CMenuRedoCommand>(document));
    menu.AddItem("ReplaceText", "<position> <text>", make_unique<CMenuReplaceTextCommand>(document));
    menu.AddItem("ResizeImage", "<position> <width> <height>", make_unique<CMenuResizeImageCommand>(document));
    menu.AddItem("Save", "<path>", make_unique<CMenuSaveCommand>(document));
    menu.AddItem("SetTitle", "<title>", make_unique<CMenuSetTitleCommand>(document));
    menu.AddItem("Undo", "Undo", make_unique<CMenuUndoCommand>(document));

    menu.ShowInstructions();

    menu.Run();

}