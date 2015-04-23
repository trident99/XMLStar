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

#include "XMLViewer.h"
#include <QtWidgets\QFileDialog>
#include <string>
using namespace std;

XMLViewer::XMLViewer(QWidget *parent, Qt::WindowFlags flags)
	: QMainWindow(parent, flags)
{
	m_ptrModelElement = NULL;
	ui.setupUi(this);
	m_ptrApplication = NULL;
	m_ptrXMLAttributeModel = NULL;
	m_ptrXMLElementModel = NULL;
	m_ptrXMLCommentModel = NULL;
	m_ptrXMLProcessModel = NULL;
	OnIntializeDialog();
}

XMLViewer::~XMLViewer()
{
	try{
		ui.m_tvwXMLModel->setModel(NULL);
		if(this->m_ptrXMLElementModel)
		{
			delete m_ptrXMLElementModel;
			m_ptrXMLElementModel = NULL;
		};
		if(this->m_ptrModelElement)
		{
			//delete m_ptrModelElement;
			m_ptrModelElement = NULL;
		};
	}catch(...){
		//error continue
	}
}

void XMLViewer::Set_ptrApplication(QApplication * ptrApp)
{
	if(ptrApp)
	{
	m_ptrApplication = ptrApp;
	}
	return;
};


//!Calls STANDARD PUBLIC FUNCTIONS THAT EVERY MAIN DIALOG SHOULD HAVE
void XMLViewer::OnIntializeDialog(void)
{
	this->OnInitializeForms();
	this->OnInitializeControls();
	this->OnInitializeDependantControls();
	this->CreateMenus();
	this->CreateContextMenus();
	this->CreateActions();
	this->CreateToolBars();
	this->CreateStatusBar();
};
//!Initialize the child forms for the GUI
void XMLViewer::OnInitializeForms(void)
{
	//THIS FUNCTION IS WHERE ALL SUB-FORMS AND DIALOGS ARE CREATED AND INTIALIZED
	return;	
};
//!Initialize the Controls for the GUI
void XMLViewer::OnInitializeControls(void)
{

	return;
};
//!Initialize the Dependant Controls that are linked to information in the model
void XMLViewer::OnInitializeDependantControls(void)
{
	//THIS FUNCTION IS WHERE ALL INITIALIZATION OF *MODEL DEPENDENT* GUI CONTROLS IS PERFORMED
	//CREATE THE XML Element MODEL
	m_ptrXMLElementModel = new QXMLElementModel(this);
	m_ptrModelElement = new XMLElement();
	m_ptrModelElement->Set_blnRootNode(true);

	ui.m_tvwXMLModel->setModel(m_ptrXMLElementModel);
	m_ptrXMLElementModel->Set_ptrModelElement(m_ptrModelElement);

	m_ptrXMLAttributeModel = new QXMLAttributeModel(this);
	ui.m_tvwXMLAttributes->setModel(m_ptrXMLAttributeModel);

	m_ptrXMLCommentModel = new QXMLCommentModel(this);
	ui.m_tvwXMLComments->setModel(m_ptrXMLCommentModel);

	m_ptrXMLProcessModel = new QXMLProcessModel(this);
	ui.m_tvwXMLProcesses->setModel(m_ptrXMLProcessModel);

	//CREATE THE SCENE VIEWER
	return;
};
//!Create the Main Menu or modify the main menu programmatically
void XMLViewer::CreateMenus(void)
{
	//THIS FUNCTION IS WHERE ALL MENUS ARE CREATED
	return;
};
//!Create any popup menus for the main application GUI
void XMLViewer::CreateContextMenus(void)
{
	//THIS FUNCTION IS WHERE ALL CONTEXT MENUS ARE CREATED
	return;
};
//!Create the Actions and connect them to the slots code for handling their events
void XMLViewer::CreateActions(void)
{
	//THIS FUNCTION IS WHERE ALL ACTIONS ARE LINKED TO THEIR SLOT FUNCTIONS
	connect(ui.actionOpen_XML_File, SIGNAL(triggered()),this, SLOT(OnFile_OpenXMLFile_Clicked()) );
	connect(ui.actionSave, SIGNAL(triggered()),this, SLOT(OnFile_SaveXMLFile_Clicked()) );
	connect(ui.actionSave_As, SIGNAL(triggered()),this, SLOT(OnFile_SaveAsXMLFile_Clicked()) );
	connect(ui.actionClose_XML_File, SIGNAL(triggered()),this, SLOT(OnFile_CloseXMLFile_Clicked()) );
	connect(ui.actionExit, SIGNAL(triggered()),this, SLOT(OnFile_Exit_Clicked()) );


	connect(ui.actionLoad_Scenario_1, SIGNAL(triggered()),this, SLOT(OnLoad_TestScenario01()) );
	connect(ui.actionLoad_Scenario_2, SIGNAL(triggered()),this, SLOT(OnLoad_TestScenario02()) );
	connect(ui.actionLoad_Scenario_3, SIGNAL(triggered()),this, SLOT(OnLoad_TestScenario03()) );
	connect(ui.actionLoad_Scenario_4, SIGNAL(triggered()),this, SLOT(OnLoad_TestScenario04()) );

	connect(ui.actionSave_Scenario_1, SIGNAL(triggered()),this, SLOT(OnSave_TestScenario01()) );
	connect(ui.actionSave_Scenario_2, SIGNAL(triggered()),this, SLOT(OnSave_TestScenario02()) );
	connect(ui.actionSave_Scenario_3, SIGNAL(triggered()),this, SLOT(OnSave_TestScenario03()) );
	connect(ui.actionSave_Scenario_4, SIGNAL(triggered()),this, SLOT(OnSave_TestScenario04()) );

	connect(ui.actionRW_Scenario_1, SIGNAL(triggered()),this, SLOT(OnReadWrite_TestScenario01()) );
	connect(ui.actionRW_Scenario_2, SIGNAL(triggered()),this, SLOT(OnReadWrite_TestScenario02()) );
	connect(ui.actionRW_Scenario_3, SIGNAL(triggered()),this, SLOT(OnReadWrite_TestScenario03()) );
	connect(ui.actionRW_Scenario_4, SIGNAL(triggered()),this, SLOT(OnReadWrite_TestScenario04()) );
		//Connect the tree view control to selection code.
	connect(ui.m_tvwXMLModel->selectionModel(),SIGNAL(currentChanged(const QModelIndex & ,const QModelIndex &)),this,SLOT(OnTvwXMLModelSelectNode(const QModelIndex &,const QModelIndex &)) );

	return;
};
//!Create any tool bars needed for the main application GUI
void XMLViewer::CreateToolBars(void)
{
	//THIS FUNCTION IS WHERE ALL TOOL BARS ARE CREATED
	return;
};
//!Initialize the status bar for the main application GUI
void XMLViewer::CreateStatusBar(void)
{
	//THIS FUNCTION IS WHERE ALL STATUS BAR INITIALIZATION AND CUSTOMIZATION IS PERFORMED
	return;
};

void XMLViewer::OnFile_NewXMLFile_Clicked(void)
{
	return;
};

void XMLViewer::OnFile_OpenXMLFile_Clicked(void)
{
	int i, intReturn;
	QString strFileName;
	QFileDialog dlgOpenFile;
	XMLReader objReader;
	strFileName = dlgOpenFile.getOpenFileName( this, QString( "OPEN XML FILE" ), "", "XML Files (*.xml);;Any File (*.*)" );

	ui.m_tvwXMLModel->setEnabled(false);
	try{
		if(strFileName.isEmpty())
		{
			ui.m_tvwXMLModel->setEnabled(true);
			return;
		}
		std::ifstream objFile(strFileName.toStdString().c_str());
		if(objFile)
		{
			objReader.LoadXMLTree(m_ptrModelElement,objFile);
			this->m_ptrXMLElementModel->UpdateModel();
		}//end valid ifstream check
	}catch(...){
		ui.m_tvwXMLModel->setEnabled(true);
		return;
	};
	ui.m_tvwXMLModel->setEnabled(true);
	return;
};

void XMLViewer::OnFile_SaveXMLFile_Clicked(void)
{
	int i, intReturn;
	XMLWriter objWriter;
	QFileDialog dlgSaveFile;
	QString strFileName = dlgSaveFile.getSaveFileName(this, tr("Save File"),
                            "output.xml",
                            tr("XML File (*.xml);;Any File (*.*)"));

	if(strFileName.isEmpty())
	{
		return;
	};
	std::ofstream objFile(strFileName.toStdString().c_str());
	if(objFile)
	{
			objWriter.SaveXMLTree(m_ptrModelElement,objFile,true);
			this->m_ptrXMLElementModel->UpdateModel();
	};

	return;
};

void XMLViewer::OnFile_SaveAsXMLFile_Clicked(void)
{
	return;
};

void XMLViewer::OnFile_CloseXMLFile_Clicked(void)
{
	this->m_ptrModelElement->Clear();
	this->m_ptrXMLElementModel->UpdateModel();
	return;
};

void XMLViewer::OnFile_Exit_Clicked(void)
{
	if(this->m_ptrApplication)
	{
		this->m_ptrApplication->quit();
	};
};
//! This SLOT Action that updates the context specific tree values based on the user selected node. Gets triggered
void XMLViewer::OnTvwXMLModelSelectNode(const QModelIndex & objCurrIndex,const QModelIndex & objPrevIndex)
{
	XMLElement * ptrCurrElement = NULL;
	std::string strTemp;
	try
	{
		if(!objCurrIndex.isValid())
		{
			return;
		}
		ptrCurrElement = static_cast<XMLElement*>( objCurrIndex.internalPointer() );
		if(ptrCurrElement)
		{
			strTemp = ptrCurrElement->Get_strName();
			ui.m_txtNodeName->setText(strTemp.c_str());

			strTemp = ptrCurrElement->Get_strValue();
			ui.m_txtNodeValue->setText(strTemp.c_str());
		};
		//set the attribute selection model element
		m_ptrXMLAttributeModel->Set_ptrElement(ptrCurrElement);
		m_ptrXMLAttributeModel->UpdateModel();

		m_ptrXMLCommentModel->Set_ptrElement(ptrCurrElement);
		m_ptrXMLCommentModel->UpdateModel();

		m_ptrXMLProcessModel->Set_ptrElement(ptrCurrElement);
		m_ptrXMLProcessModel->UpdateModel();

		return;	
	}catch(...){
		_cprintf("XML TREEVIEW: OnTvwSelectNode: Error selecting current node in tree view!\n");
	}	
};



void XMLViewer::OnLoad_TestScenario01(void)
{
	int intReturn;
	if(m_ptrXMLElementModel)
	{
		//m_ptrXMLElementModel->Clear_ptrModelElement();
		std::string strTestScenario01;
		XMLElementIndex objRootIndex;
		XMLReader objReader;
		//clear the element
		m_ptrModelElement->Clear();
		this->m_ptrXMLElementModel->UpdateModel();
		strTestScenario01 =
			"<XMLNode>MYVALUE \
			<!--This is my Comment, XML is Cool--> \
			<m_strName>Object A</m_strName> \
			<XMLNode> \
			<?MORE PROCESSING INSTRUCTIONS?> \
			<m_strName>Object B</m_strName> \
			</XMLNode> \
			</XMLNode>";
		objReader.LoadXMLTree(m_ptrModelElement,strTestScenario01,objRootIndex);
		this->m_ptrXMLElementModel->UpdateModel();
	};
	return;
};
void XMLViewer::OnLoad_TestScenario02(void)
{
	int intReturn;
	if(m_ptrXMLElementModel)
	{
		//m_ptrXMLElementModel->Clear_ptrModelElement();
		std::string strTestScenario02;
		XMLElementIndex objRootIndex;
		XMLReader objReader;
		//clear the element
		m_ptrModelElement->Clear();
		this->m_ptrXMLElementModel->UpdateModel();
		strTestScenario02 =
			"<?PROCESSING INSTRUCTIONS HERE?> \
			<XMLNode strTypeName = 'MYNODE' intNumDimensions = '2'> \
			<m_strName>Object A</m_strName> \
			<XMLNode> \
			<m_strName>Object B</m_strName> \
			</XMLNode> \
			</XMLNode>";
		objReader.LoadXMLTree(m_ptrModelElement,strTestScenario02,objRootIndex);
		this->m_ptrXMLElementModel->UpdateModel();
	};
	return;
};
void XMLViewer::OnLoad_TestScenario03(void)
{


		int intReturn;
	if(m_ptrXMLElementModel)
	{
		//m_ptrXMLElementModel->Clear_ptrModelElement();
		std::string strTestScenario03;
		XMLElementIndex objRootIndex;
		XMLReader objReader;
		//clear the element
		m_ptrModelElement->Clear();
		this->m_ptrXMLElementModel->UpdateModel();
		strTestScenario03 =
			"<strPolyline m_strTypeName = 'ClsGeomPolyLine' strBaseName = 'ORSSerializable'> \
	<m_sngObjectVersion m_strTypeName = 'STRING'>1</m_sngObjectVersion> \
	<m_lngObjectIndex m_strTypeName = 'LONG'>-1</m_lngObjectIndex> \
	<m_strObjectClassName m_strTypeName = 'STRING'>ClsGeomPolyLine</m_strObjectClassName> \
	<m_strObjectName m_strTypeName = 'STRING'>nil</m_strObjectName> \
	<m_strObjectDescription m_strTypeName = 'STRING'>nil</m_strObjectDescription> \
	<m_strObjectGUID m_strTypeName = 'GUID'/> \
	<m_strEnumObjectType m_strTypeName = 'STRING'>POLYLINE</m_strEnumObjectType> \
	<m_blnPolylineClosed m_strTypeName = 'BOOL'>FALSE</m_blnPolylineClosed> \
	<m_intRed>0</m_intRed> \
	<m_intGreen>255</m_intGreen> \
	<m_intBlue>120</m_intBlue> \
	<m_arrPtrPointCollection m_strTypeName = 'VECTOR' m_intNumDimensions = '1'> \
		<ITEM_0 m_strTypeName = 'ClsGeomPoint3D'> \
			<m_dblX m_strTypeName = 'DOUBLE'>32.0002</m_dblX> \
			<m_dblY m_strTypeName = 'DOUBLE'>-6.36683</m_dblY> \
			<m_dblZ m_strTypeName = 'DOUBLE'>2.5</m_dblZ> \
		</ITEM_0> \
		<ITEM_1><m_dblX>30.6724</m_dblX><m_dblY>-6.31941</m_dblY><m_dblZ>2.5</m_dblZ></ITEM_1> \
		<ITEM_2><m_dblX>29.3755</m_dblX><m_dblY>-6.23663</m_dblY><m_dblZ>2.5</m_dblZ></ITEM_2> \
		<ITEM_3><m_dblX>28.1637</m_dblX><m_dblY>-6.12206</m_dblY><m_dblZ>2.5</m_dblZ></ITEM_3> \
		<ITEM_4><m_dblX>27.0187</m_dblX><m_dblY>-5.97415</m_dblY><m_dblZ>2.5</m_dblZ></ITEM_4> \
		<ITEM_5><m_dblX>25.8915</m_dblX><m_dblY>-5.79086</m_dblY><m_dblZ>2.5</m_dblZ></ITEM_5> \
		<ITEM_6><m_dblX>24.5681</m_dblX><m_dblY>-5.54332</m_dblY><m_dblZ>2.5</m_dblZ></ITEM_6> \
		<ITEM_7><m_dblX>20.0002</m_dblX><m_dblY>-4.5985</m_dblY><m_dblZ>2.5</m_dblZ></ITEM_7> \
		<ITEM_8><m_dblX>20.0002</m_dblX><m_dblY>4.59852</m_dblY><m_dblZ>2.5</m_dblZ></ITEM_8> \
		<ITEM_9><m_dblX>24.5694</m_dblX><m_dblY>5.54362</m_dblY><m_dblZ>2.5</m_dblZ></ITEM_9> \
		<ITEM_10><m_dblX>25.8991</m_dblX><m_dblY>5.79216</m_dblY><m_dblZ>2.5</m_dblZ></ITEM_10> \
		<ITEM_11><m_dblX>27.021</m_dblX><m_dblY>5.97444</m_dblY><m_dblZ>2.5</m_dblZ></ITEM_11> \
		<ITEM_12><m_dblX>28.1638</m_dblX><m_dblY>6.12203</m_dblY><m_dblZ>2.5</m_dblZ></ITEM_12> \
		<ITEM_13><m_dblX>29.3773</m_dblX><m_dblY>6.23676</m_dblY><m_dblZ>2.5</m_dblZ></ITEM_13> \
		<ITEM_14><m_dblX>30.6742</m_dblX><m_dblY>6.31957</m_dblY><m_dblZ>2.5</m_dblZ></ITEM_14> \
		<ITEM_15><m_dblX>32.0002</m_dblX><m_dblY>6.36686</m_dblY><m_dblZ>2.5</m_dblZ></ITEM_15> \
	</m_arrPtrPointCollection> \
</strPolyline> \
			";
		objReader.LoadXMLTree(m_ptrModelElement,strTestScenario03,objRootIndex);
		this->m_ptrXMLElementModel->UpdateModel();
	};
	return;



};
void XMLViewer::OnLoad_TestScenario04(void)
{
	int intReturn;
	if(m_ptrXMLElementModel)
	{
		//m_ptrXMLElementModel->Clear_ptrModelElement();
		std::string strTestScenario01;
		XMLElementIndex objRootIndex;
		XMLReader objReader;
		//clear the element
		m_ptrModelElement->Clear();
		this->m_ptrXMLElementModel->UpdateModel();
		strTestScenario01 =
			"<XMLNode>MYVALUE \
			<!--This is my Comment, XML is Cool--> \
			<m_strName>Object A</m_strName> \
				<XMLNode>Nest Level 1 \
				<?MORE PROCESSING INSTRUCTIONS?> \
				<m_strName>Object B</m_strName> \
					<XMLNode>Nest Level 2 \
						<XMLNode>1</XMLNode> \
					</XMLNode> \
					<XMLNode>Nest Level 2 \
						<XMLNode>Nest Level 3\
						</XMLNode> \
					</XMLNode> \
				</XMLNode> \
			</XMLNode>";
		objReader.LoadXMLTree(m_ptrModelElement,strTestScenario01,objRootIndex);
		this->m_ptrXMLElementModel->UpdateModel();
	};
	return;

};

void XMLViewer::OnSave_TestScenario01(void)
{
	//create the tree manually
	int intReturn;
	std::string strTemp;
	XMLElement objTempRoot;
	XMLWriter objWriter;

	XMLElement * ptrSubNode = NULL;
	XMLAttribute * ptrCurrAttribute = NULL;
	objTempRoot.Set_blnNullNode(false);
	objTempRoot.Set_blnRootNode(true);
	strTemp = "ClsRootNode";
	objTempRoot.Set_strName(strTemp);

	ptrCurrAttribute = objTempRoot.AddAttribute();
	strTemp = "m_strType";
	ptrCurrAttribute->Set_strName(strTemp);
	ptrCurrAttribute->Set_enumValueType(XML_STRING);
	strTemp = "ClsXMLElement";
	ptrCurrAttribute->Set_strValue(strTemp);


	ptrSubNode = objTempRoot.AddSubElement();
	strTemp = "ClsSubNode";
	ptrSubNode->Set_strName(strTemp);
	strTemp = "MYVALUE IS HERE";
	ptrSubNode->Set_strValue(strTemp);

	ptrCurrAttribute = ptrSubNode->AddAttribute();
	strTemp = "m_sngMyFloat";
	ptrCurrAttribute->Set_strName(strTemp);
	ptrCurrAttribute->Set_enumValueType(XML_FLOAT);
	ptrCurrAttribute->Set_strValue(float(3.14159));

	ptrCurrAttribute = ptrSubNode->AddAttribute();
	strTemp = "m_sngMyInt";
	ptrCurrAttribute->Set_strName(strTemp);
	ptrCurrAttribute->Set_enumValueType(XML_INT);
	ptrCurrAttribute->Set_strValue(int(15));

	ptrSubNode = objTempRoot.AddSubElement();
	strTemp = "ClsSubNode2";
	ptrSubNode->Set_strName(strTemp);
	ptrSubNode->Set_blnNullNode(true);

	ptrCurrAttribute = ptrSubNode->AddAttribute();
	strTemp = "m_sngMyDouble";
	ptrCurrAttribute->Set_strName(strTemp);
	ptrCurrAttribute->Set_enumValueType(XML_DOUBLE);
	ptrCurrAttribute->Set_strValue(float(3.123456789012));

	//string element
	std::string strXMLOut;
	
	objWriter.SaveXMLTree(&objTempRoot,strXMLOut,true);
	ui.m_txtNodeValue->setText(strXMLOut.c_str());
	return;
};
void XMLViewer::OnSave_TestScenario02(void)
{
	//create the tree manually
	int intReturn;
	std::string strTemp;
	XMLElement objTempRoot;
	XMLWriter objWriter;
	XMLElement * ptrSubNode = NULL;
	XMLAttribute * ptrCurrAttribute = NULL;

	objTempRoot.Set_blnNullNode(false);
	objTempRoot.Set_blnRootNode(true);
	strTemp = "ClsRootNode";
	objTempRoot.Set_strName(strTemp);

	ptrCurrAttribute = objTempRoot.AddAttribute();
	strTemp = "m_strType";
	ptrCurrAttribute->Set_strName(strTemp);
	ptrCurrAttribute->Set_enumValueType(XML_STRING);
	strTemp = "ClsXMLElement";
	ptrCurrAttribute->Set_strValue(strTemp);


	ptrSubNode = objTempRoot.AddSubElement();
	strTemp = "ClsSubNode";
	ptrSubNode->Set_strName(strTemp);
	strTemp = "MYVALUE IS HERE";
	ptrSubNode->Set_strValue(strTemp);

	ptrCurrAttribute = ptrSubNode->AddAttribute();
	strTemp = "m_sngMyFloat";
	ptrCurrAttribute->Set_strName(strTemp);
	ptrCurrAttribute->Set_enumValueType(XML_FLOAT);
	ptrCurrAttribute->Set_strValue(float(3.14159));

	ptrCurrAttribute = ptrSubNode->AddAttribute();
	strTemp = "m_sngMyInt";
	ptrCurrAttribute->Set_strName(strTemp);
	ptrCurrAttribute->Set_enumValueType(XML_INT);
	ptrCurrAttribute->Set_strValue(int(15));

	ptrSubNode = objTempRoot.AddSubElement();
	strTemp = "ClsSubNode2";
	ptrSubNode->Set_strName(strTemp);
	ptrSubNode->Set_blnNullNode(true);

	ptrCurrAttribute = ptrSubNode->AddAttribute();
	strTemp = "m_sngMyDouble";
	ptrCurrAttribute->Set_strName(strTemp);
	ptrCurrAttribute->Set_enumValueType(XML_DOUBLE);
	ptrCurrAttribute->Set_strValue(float(3.123456789012));

	//string element
	std::string strXMLOut;

	objWriter.SaveXMLTree(&objTempRoot,strXMLOut,true);
	ui.m_txtNodeValue->setText(strXMLOut.c_str());
	return;
};
void XMLViewer::OnSave_TestScenario03(void)
{

};
void XMLViewer::OnSave_TestScenario04(void)
{

};

void XMLViewer::OnReadWrite_TestScenario01(void)
{

};
void XMLViewer::OnReadWrite_TestScenario02(void)
{

};
void XMLViewer::OnReadWrite_TestScenario03(void)
{

};
void XMLViewer::OnReadWrite_TestScenario04(void)
{

};