/*
**	This file is part of the XMLStar.
**	This software was developed by:
**	
**  Anthony Daniels, Mi Yan
**	The University of Michigan
**	Department of Naval Architecture & Marine Engineering
**	Department of Computer Science
**
**  XMLStar is free software: you can redistribute it and/or modify
**  it under the terms of the GNU Lesser General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  The United States of America Department of Defense has unlimited 
**	usage, redistribution, and modification rights to XMLStar.
**
**  XMLStar is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU Lesser General Public License for more details.
**
**  You should have received a copy of the GNU Lesser General Public License
**  along with XMLStar.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef XMLViewer_H
#define XMLViewer_H
#include <QtCore>
#include <QtGui>
#include <QtWidgets\QMainWindow>
#include ".\modLibraryRefs.h"
#include ".\QXMLElementModel.h"
#include ".\QXMLAttributeModel.h"
#include ".\QXMLCommentModel.h"
#include ".\QXMLProcessModel.h"
#include "ui_XMLViewer.h"


class XMLViewer : public QMainWindow
{
	Q_OBJECT

public:
	XMLViewer(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~XMLViewer();

	void Set_ptrApplication(QApplication * ptrApp);

	//!Calls STANDARD PUBLIC FUNCTIONS THAT EVERY MAIN DIALOG SHOULD HAVE
	void OnIntializeDialog(void);
	//!Initialize the child forms for the GUI
	virtual void OnInitializeForms(void);
	//!Initialize the Controls for the GUI
	virtual void OnInitializeControls(void);
	//!Initialize the Dependant Controls that are linked to information in the model
	virtual void OnInitializeDependantControls(void);
	//!Create the Main Menu Actions and connect them to the slots code for handling their events
	virtual void CreateActions(void);
	//!Create the Main Menu or modify the main menu programmatically
	virtual void CreateMenus(void);
	//!Create any popup menus for the main application GUI
	virtual void CreateContextMenus(void);
	//!Create any tool bars needed for the main application GUI
	virtual void CreateToolBars(void);
	//!Initialize the status bar for the main application GUI
	virtual void CreateStatusBar(void);

	public slots:
		void OnFile_NewXMLFile_Clicked(void);
		void OnFile_OpenXMLFile_Clicked(void);
		void OnFile_SaveXMLFile_Clicked(void);
		void OnFile_SaveAsXMLFile_Clicked(void);
		void OnFile_CloseXMLFile_Clicked(void);
		void OnFile_Exit_Clicked(void);

		void OnTvwXMLModelSelectNode(const QModelIndex & objCurrIndex,const QModelIndex & objPrevIndex);



		private slots:
			void OnLoad_TestScenario01(void);
			void OnLoad_TestScenario02(void);
			void OnLoad_TestScenario03(void);
			void OnLoad_TestScenario04(void);

			void OnSave_TestScenario01(void);
			void OnSave_TestScenario02(void);
			void OnSave_TestScenario03(void);
			void OnSave_TestScenario04(void);

			void OnReadWrite_TestScenario01(void);
			void OnReadWrite_TestScenario02(void);
			void OnReadWrite_TestScenario03(void);
			void OnReadWrite_TestScenario04(void);
private:
	Ui::XMLViewerClass ui;
	//
	QApplication * m_ptrApplication;

	QXMLElementModel * m_ptrXMLElementModel;

	QXMLAttributeModel * m_ptrXMLAttributeModel;

	QXMLCommentModel * m_ptrXMLCommentModel;

	QXMLProcessModel * m_ptrXMLProcessModel;

	XMLElement * m_ptrModelElement;

	
};

#endif // XMLViewer_H
