#pragma once
//#include <string>
#include <istream>
#include <string>
#include "functions.h"
namespace KNNProject {

	using namespace System;
	using namespace System::Runtime::InteropServices;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Diagnostics;
//	using  std;
	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^  ofdlg1;
	protected: 

	protected: 
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openTrainFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openTestFileToolStripMenuItem;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ToolStripMenuItem^  showTrainFileToolStripMenuItem;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ToolStripMenuItem^  normalizeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  trainFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  showClassesFromTrainToolStripMenuItem;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ToolStripMenuItem^  testToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  matToArrayToMatToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::RichTextBox^  richTextBox3;
	private: System::Windows::Forms::RichTextBox^  richTextBox4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::ToolStripMenuItem^  showTestFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  showTestClassesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  kNNToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::ToolStripMenuItem^  minAverageDistancesOfEachClassToolStripMenuItem;
	private: System::Windows::Forms::Label^  label8;

	private: System::Windows::Forms::RichTextBox^  richTextBox5;
	private: System::Windows::Forms::ToolStripMenuItem^  trainCentroidsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  testCentroidsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  showTrainOutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  kNNSumDistamcesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  trainCentroidUsingMediansToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  testCentroidsUsingMediansToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  trainQuartilesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  testQuartilesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  showTrain2OutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  kNNChangeKFrom1ToSqrtTrnsetToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  kNNToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  trainBoundariesMedianRowsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  testBoundariesMedianRowsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  trainBndryAvgQuartileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  testBndryAvgQuartileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  testBndryAvgQuarEDToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  kNNAlternativesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  nNMajorityToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  nNMsxDisMinorityToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  nNToolStripMenuItem;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::ToolStripMenuItem^  trainingAveragesOfSubClassesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  testAveragesOfSubClassesToolStripMenuItem;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::ToolStripMenuItem^  showTrain3OutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  testAverageOfSubClsVotesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  genaticAlgorithmsToChooseBestExamToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  testGAToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  testGANNMajorityToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  weightsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  trainWeightsUsingChiToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  trainWeightUsingNNToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  trainBestFVsNNAccuracyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  testTrnBestNNMajorityToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  trainUsingMinimumDistanceToGetBoundaryPointsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  testMDBPToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  trainGAOfNonZeroMDBPToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  testGAMDBPToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  showTrainOut1ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  kNNChangeKFrom1ToSqrtNOddKsToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  kNNChangeKFrom1ToSqrtNOddKsWeightsToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  kNNChangeKFrom1ToSqrtNKsWeightsToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  cpmprehinsiveTestsToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  testKnnWithDifferenToolStripMenuItem;
private: System::Windows::Forms::ProgressBar^  progressBar1;
private: System::Windows::Forms::ToolStripMenuItem^  normsToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  eDNormBinsearchKNNToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  kNNChangeKFrom1ToSqrtNKsWeightsWithIINdxToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  invertedIndexToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  testKnnWithDifferentKToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  testIINCOnAllDatasetsToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  testKNNChangeKFrom1ToSqrtNOddWeightsToolStripMenuItem;
private: System::Windows::Forms::CheckBox^  checkBox1;
private: System::Windows::Forms::ToolStripMenuItem^  testKNNChangeKFrom1ToHalfSqrtNOddWeightsToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  testKNNKfrom1ToSrtnOddWeightsNewToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  testKnnWithK304560ToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  knnOddEightsNewWithDistanceToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  kNFToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  ensimbleIINCToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  reduceFeaturesByHalfToolStripMenuItem;
private: System::Windows::Forms::TextBox^  textBox3;
private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::ToolStripMenuItem^  clacMaxValuesInMatrixToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  tanhTestToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  minMaxNewToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  setRangeToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  normBinsearchKnnDivByComplementToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  kNNWithBaggingToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  clusteringToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  kmeanToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  kmeanHasDistToolStripMenuItem;
private: System::Windows::Forms::Button^  button5;
private: System::Windows::Forms::Button^  button6;
private: System::Windows::Forms::ToolStripMenuItem^  testToolStripMenuItem1;
private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::ToolStripMenuItem^  noiseToolStripMenuItem;
private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::TextBox^  textBox4;
private: System::Windows::Forms::Label^  label14;
private: System::Windows::Forms::CheckBox^  checkBox2;
private: System::Windows::Forms::ToolStripMenuItem^  train01NormsBtreeToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  test01NormsBtreeNNToolStripMenuItem;
private: System::Windows::Forms::CheckBox^  checkBox3;
private: System::Windows::Forms::ToolStripMenuItem^  test01NormsBtreeWithLognExamplesToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  farthestDistancesToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  bFFarthestDistanceToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  te;
private: System::Windows::Forms::ToolStripMenuItem^  tree2RndpntToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  trainBtreeToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  testTreeToLeafToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  testTreeToKlognToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  trainBtr2pMinMaxNormToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  testTree2pmnmxToLeafToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  testAllWithNFoldToolStripMenuItem;
private: System::Windows::Forms::TextBox^  textBox5;
private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::ToolStripMenuItem^  openTheFirst1000RowsToolStripMenuItem;
private: System::Windows::Forms::CheckBox^  checkBox4;
private: System::Windows::Forms::ToolStripMenuItem^  testALLWithNFoldEfficientToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  openTestFileEfficiemtlyToolStripMenuItem;
private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::ToolStripMenuItem^  testAllOnReadyTrainAndTestToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  kNNNFoldsToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  trainBST2ExtremPointsToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  testBST2ExtremPointsToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  trainFurthestPBSTToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  testFurthestPBSTToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  multiTreesToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  normBTreePerClassToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  testNormBtreePerClassToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  decsionTreesToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  furthestPointDTToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  testFurthesPointDTToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  fixClassesToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  cBIRToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  indextraindatUsing2FPBSTToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  testIndexToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  randomMinMaxClassDTToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  testRandomMinMaxClassDTToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  zNormalizationToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  kNNNfoldMultiRunsToolStripMenuItem;
private: System::Windows::Forms::Label^  label16;












	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ofdlg1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openTheFirst1000RowsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openTrainFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openTestFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showTrainFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showClassesFromTrainToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showTestFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showTestClassesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showTrainOutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showTrain2OutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showTrain3OutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showTrainOut1ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openTestFileEfficiemtlyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fixClassesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->normalizeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->reduceFeaturesByHalfToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clacMaxValuesInMatrixToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tanhTestToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->minMaxNewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->setRangeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->noiseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zNormalizationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->matToArrayToMatToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kNNToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->minAverageDistancesOfEachClassToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainCentroidsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testCentroidsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kNNSumDistamcesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainCentroidUsingMediansToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testCentroidsUsingMediansToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainQuartilesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testQuartilesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kNNChangeKFrom1ToSqrtTrnsetToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kNNToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainBoundariesMedianRowsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testBoundariesMedianRowsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainBndryAvgQuartileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testBndryAvgQuartileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testBndryAvgQuarEDToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kNNNFoldsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kNNNfoldMultiRunsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kNNAlternativesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nNMajorityToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nNMsxDisMinorityToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nNToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainingAveragesOfSubClassesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testAveragesOfSubClassesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testAverageOfSubClsVotesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->genaticAlgorithmsToChooseBestExamToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testGAToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testGANNMajorityToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainBestFVsNNAccuracyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testTrnBestNNMajorityToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->weightsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainWeightsUsingChiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainWeightUsingNNToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainUsingMinimumDistanceToGetBoundaryPointsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testMDBPToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainGAOfNonZeroMDBPToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testGAMDBPToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kNNChangeKFrom1ToSqrtNOddKsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kNNChangeKFrom1ToSqrtNOddKsWeightsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kNNChangeKFrom1ToSqrtNKsWeightsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kNNChangeKFrom1ToSqrtNKsWeightsWithIINdxToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->invertedIndexToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kNFToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ensimbleIINCToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cpmprehinsiveTestsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testKnnWithDifferenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testKnnWithDifferentKToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testIINCOnAllDatasetsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testKNNChangeKFrom1ToSqrtNOddWeightsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testKNNChangeKFrom1ToHalfSqrtNOddWeightsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testKNNKfrom1ToSrtnOddWeightsNewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testKnnWithK304560ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->knnOddEightsNewWithDistanceToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->normsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->eDNormBinsearchKNNToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->normBinsearchKnnDivByComplementToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kNNWithBaggingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->train01NormsBtreeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->test01NormsBtreeNNToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->test01NormsBtreeWithLognExamplesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->te = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clusteringToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kmeanToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kmeanHasDistToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->farthestDistancesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->bFFarthestDistanceToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tree2RndpntToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testALLWithNFoldEfficientToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainBtreeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testTreeToLeafToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testTreeToKlognToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainBtr2pMinMaxNormToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testTree2pmnmxToLeafToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testAllWithNFoldToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testAllOnReadyTrainAndTestToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainBST2ExtremPointsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testBST2ExtremPointsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainFurthestPBSTToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testFurthestPBSTToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->multiTreesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->normBTreePerClassToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testNormBtreePerClassToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->decsionTreesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->furthestPointDTToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testFurthesPointDTToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->randomMinMaxClassDTToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testRandomMinMaxClassDTToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cBIRToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->indextraindatUsing2FPBSTToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testIndexToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox4 = (gcnew System::Windows::Forms::RichTextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->richTextBox5 = (gcnew System::Windows::Forms::RichTextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// ofdlg1
			// 
			this->ofdlg1->FileName = L"openFileDialog1";
			this->ofdlg1->Multiselect = true;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(14) {
				this->fileToolStripMenuItem,
					this->normalizeToolStripMenuItem, this->testToolStripMenuItem, this->kNNAlternativesToolStripMenuItem, this->weightsToolStripMenuItem,
					this->newToolStripMenuItem, this->cpmprehinsiveTestsToolStripMenuItem, this->normsToolStripMenuItem, this->clusteringToolStripMenuItem,
					this->farthestDistancesToolStripMenuItem, this->tree2RndpntToolStripMenuItem, this->multiTreesToolStripMenuItem, this->decsionTreesToolStripMenuItem,
					this->cBIRToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1096, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(13) {
				this->openTheFirst1000RowsToolStripMenuItem,
					this->openTrainFileToolStripMenuItem, this->openTestFileToolStripMenuItem, this->showTrainFileToolStripMenuItem, this->showClassesFromTrainToolStripMenuItem,
					this->showTestFileToolStripMenuItem, this->showTestClassesToolStripMenuItem, this->showTrainOutToolStripMenuItem, this->showTrain2OutToolStripMenuItem,
					this->showTrain3OutToolStripMenuItem, this->showTrainOut1ToolStripMenuItem, this->openTestFileEfficiemtlyToolStripMenuItem, this->fixClassesToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(35, 20);
			this->fileToolStripMenuItem->Text = L"file";
			// 
			// openTheFirst1000RowsToolStripMenuItem
			// 
			this->openTheFirst1000RowsToolStripMenuItem->Name = L"openTheFirst1000RowsToolStripMenuItem";
			this->openTheFirst1000RowsToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->openTheFirst1000RowsToolStripMenuItem->Text = L"open Train file Efficiently";
			this->openTheFirst1000RowsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::openTheFirst1000RowsToolStripMenuItem_Click);
			// 
			// openTrainFileToolStripMenuItem
			// 
			this->openTrainFileToolStripMenuItem->Name = L"openTrainFileToolStripMenuItem";
			this->openTrainFileToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->openTrainFileToolStripMenuItem->Text = L"open train file";
			this->openTrainFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::openTrainFileToolStripMenuItem_Click);
			// 
			// openTestFileToolStripMenuItem
			// 
			this->openTestFileToolStripMenuItem->Name = L"openTestFileToolStripMenuItem";
			this->openTestFileToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->openTestFileToolStripMenuItem->Text = L"open test file";
			this->openTestFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::openTestFileToolStripMenuItem_Click);
			// 
			// showTrainFileToolStripMenuItem
			// 
			this->showTrainFileToolStripMenuItem->Name = L"showTrainFileToolStripMenuItem";
			this->showTrainFileToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->showTrainFileToolStripMenuItem->Text = L"show train file";
			this->showTrainFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::showTrainFileToolStripMenuItem_Click);
			// 
			// showClassesFromTrainToolStripMenuItem
			// 
			this->showClassesFromTrainToolStripMenuItem->Name = L"showClassesFromTrainToolStripMenuItem";
			this->showClassesFromTrainToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->showClassesFromTrainToolStripMenuItem->Text = L"show classes from train";
			this->showClassesFromTrainToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::showClassesFromTrainToolStripMenuItem_Click);
			// 
			// showTestFileToolStripMenuItem
			// 
			this->showTestFileToolStripMenuItem->Name = L"showTestFileToolStripMenuItem";
			this->showTestFileToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->showTestFileToolStripMenuItem->Text = L"show test file";
			this->showTestFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::showTestFileToolStripMenuItem_Click);
			// 
			// showTestClassesToolStripMenuItem
			// 
			this->showTestClassesToolStripMenuItem->Name = L"showTestClassesToolStripMenuItem";
			this->showTestClassesToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->showTestClassesToolStripMenuItem->Text = L"show test classes";
			this->showTestClassesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::showTestClassesToolStripMenuItem_Click);
			// 
			// showTrainOutToolStripMenuItem
			// 
			this->showTrainOutToolStripMenuItem->Name = L"showTrainOutToolStripMenuItem";
			this->showTrainOutToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->showTrainOutToolStripMenuItem->Text = L"show train out";
			this->showTrainOutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::showTrainOutToolStripMenuItem_Click);
			// 
			// showTrain2OutToolStripMenuItem
			// 
			this->showTrain2OutToolStripMenuItem->Name = L"showTrain2OutToolStripMenuItem";
			this->showTrain2OutToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->showTrain2OutToolStripMenuItem->Text = L"Show train2 out";
			this->showTrain2OutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::showTrain2OutToolStripMenuItem_Click);
			// 
			// showTrain3OutToolStripMenuItem
			// 
			this->showTrain3OutToolStripMenuItem->Name = L"showTrain3OutToolStripMenuItem";
			this->showTrain3OutToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->showTrain3OutToolStripMenuItem->Text = L"show train3 out";
			this->showTrain3OutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::showTrain3OutToolStripMenuItem_Click);
			// 
			// showTrainOut1ToolStripMenuItem
			// 
			this->showTrainOut1ToolStripMenuItem->Name = L"showTrainOut1ToolStripMenuItem";
			this->showTrainOut1ToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->showTrainOut1ToolStripMenuItem->Text = L"Show TrainOut1";
			this->showTrainOut1ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::showTrainOut1ToolStripMenuItem_Click);
			// 
			// openTestFileEfficiemtlyToolStripMenuItem
			// 
			this->openTestFileEfficiemtlyToolStripMenuItem->Name = L"openTestFileEfficiemtlyToolStripMenuItem";
			this->openTestFileEfficiemtlyToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->openTestFileEfficiemtlyToolStripMenuItem->Text = L"open test file Efficiently";
			this->openTestFileEfficiemtlyToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::openTestFileEfficiemtlyToolStripMenuItem_Click);
			// 
			// fixClassesToolStripMenuItem
			// 
			this->fixClassesToolStripMenuItem->Name = L"fixClassesToolStripMenuItem";
			this->fixClassesToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->fixClassesToolStripMenuItem->Text = L"Fix classes";
			this->fixClassesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::fixClassesToolStripMenuItem_Click);
			// 
			// normalizeToolStripMenuItem
			// 
			this->normalizeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->trainFileToolStripMenuItem,
					this->reduceFeaturesByHalfToolStripMenuItem, this->clacMaxValuesInMatrixToolStripMenuItem, this->tanhTestToolStripMenuItem, this->minMaxNewToolStripMenuItem,
					this->setRangeToolStripMenuItem, this->noiseToolStripMenuItem, this->zNormalizationToolStripMenuItem
			});
			this->normalizeToolStripMenuItem->Name = L"normalizeToolStripMenuItem";
			this->normalizeToolStripMenuItem->Size = System::Drawing::Size(73, 20);
			this->normalizeToolStripMenuItem->Text = L"Normalize";
			// 
			// trainFileToolStripMenuItem
			// 
			this->trainFileToolStripMenuItem->Name = L"trainFileToolStripMenuItem";
			this->trainFileToolStripMenuItem->Size = System::Drawing::Size(205, 22);
			this->trainFileToolStripMenuItem->Text = L"Train file";
			this->trainFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::trainFileToolStripMenuItem_Click);
			// 
			// reduceFeaturesByHalfToolStripMenuItem
			// 
			this->reduceFeaturesByHalfToolStripMenuItem->Name = L"reduceFeaturesByHalfToolStripMenuItem";
			this->reduceFeaturesByHalfToolStripMenuItem->Size = System::Drawing::Size(205, 22);
			this->reduceFeaturesByHalfToolStripMenuItem->Text = L"Reduce features by half";
			this->reduceFeaturesByHalfToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::reduceFeaturesByHalfToolStripMenuItem_Click);
			// 
			// clacMaxValuesInMatrixToolStripMenuItem
			// 
			this->clacMaxValuesInMatrixToolStripMenuItem->Name = L"clacMaxValuesInMatrixToolStripMenuItem";
			this->clacMaxValuesInMatrixToolStripMenuItem->Size = System::Drawing::Size(205, 22);
			this->clacMaxValuesInMatrixToolStripMenuItem->Text = L"clac max values in matrix";
			this->clacMaxValuesInMatrixToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::clacMaxValuesInMatrixToolStripMenuItem_Click);
			// 
			// tanhTestToolStripMenuItem
			// 
			this->tanhTestToolStripMenuItem->Name = L"tanhTestToolStripMenuItem";
			this->tanhTestToolStripMenuItem->Size = System::Drawing::Size(205, 22);
			this->tanhTestToolStripMenuItem->Text = L"Tanh test";
			this->tanhTestToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::tanhTestToolStripMenuItem_Click);
			// 
			// minMaxNewToolStripMenuItem
			// 
			this->minMaxNewToolStripMenuItem->Name = L"minMaxNewToolStripMenuItem";
			this->minMaxNewToolStripMenuItem->Size = System::Drawing::Size(205, 22);
			this->minMaxNewToolStripMenuItem->Text = L"MinMaxNew";
			this->minMaxNewToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::minMaxNewToolStripMenuItem_Click);
			// 
			// setRangeToolStripMenuItem
			// 
			this->setRangeToolStripMenuItem->Name = L"setRangeToolStripMenuItem";
			this->setRangeToolStripMenuItem->Size = System::Drawing::Size(205, 22);
			this->setRangeToolStripMenuItem->Text = L"Set range";
			this->setRangeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::setRangeToolStripMenuItem_Click);
			// 
			// noiseToolStripMenuItem
			// 
			this->noiseToolStripMenuItem->Name = L"noiseToolStripMenuItem";
			this->noiseToolStripMenuItem->Size = System::Drawing::Size(205, 22);
			this->noiseToolStripMenuItem->Text = L"Noise";
			this->noiseToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::noiseToolStripMenuItem_Click);
			// 
			// zNormalizationToolStripMenuItem
			// 
			this->zNormalizationToolStripMenuItem->Name = L"zNormalizationToolStripMenuItem";
			this->zNormalizationToolStripMenuItem->Size = System::Drawing::Size(205, 22);
			this->zNormalizationToolStripMenuItem->Text = L"Z-Normalization";
			this->zNormalizationToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::zNormalizationToolStripMenuItem_Click);
			// 
			// testToolStripMenuItem
			// 
			this->testToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(19) {
				this->matToArrayToMatToolStripMenuItem,
					this->kNNToolStripMenuItem, this->minAverageDistancesOfEachClassToolStripMenuItem, this->trainCentroidsToolStripMenuItem, this->testCentroidsToolStripMenuItem,
					this->kNNSumDistamcesToolStripMenuItem, this->trainCentroidUsingMediansToolStripMenuItem, this->testCentroidsUsingMediansToolStripMenuItem,
					this->trainQuartilesToolStripMenuItem, this->testQuartilesToolStripMenuItem, this->kNNChangeKFrom1ToSqrtTrnsetToolStripMenuItem,
					this->kNNToolStripMenuItem1, this->trainBoundariesMedianRowsToolStripMenuItem, this->testBoundariesMedianRowsToolStripMenuItem,
					this->trainBndryAvgQuartileToolStripMenuItem, this->testBndryAvgQuartileToolStripMenuItem, this->testBndryAvgQuarEDToolStripMenuItem,
					this->kNNNFoldsToolStripMenuItem, this->kNNNfoldMultiRunsToolStripMenuItem
			});
			this->testToolStripMenuItem->Name = L"testToolStripMenuItem";
			this->testToolStripMenuItem->Size = System::Drawing::Size(40, 20);
			this->testToolStripMenuItem->Text = L"Test";
			// 
			// matToArrayToMatToolStripMenuItem
			// 
			this->matToArrayToMatToolStripMenuItem->Name = L"matToArrayToMatToolStripMenuItem";
			this->matToArrayToMatToolStripMenuItem->Size = System::Drawing::Size(261, 22);
			this->matToArrayToMatToolStripMenuItem->Text = L"mat to array to mat";
			this->matToArrayToMatToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::matToArrayToMatToolStripMenuItem_Click);
			// 
			// kNNToolStripMenuItem
			// 
			this->kNNToolStripMenuItem->Name = L"kNNToolStripMenuItem";
			this->kNNToolStripMenuItem->Size = System::Drawing::Size(261, 22);
			this->kNNToolStripMenuItem->Text = L"KNN";
			this->kNNToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::kNNToolStripMenuItem_Click);
			// 
			// minAverageDistancesOfEachClassToolStripMenuItem
			// 
			this->minAverageDistancesOfEachClassToolStripMenuItem->Name = L"minAverageDistancesOfEachClassToolStripMenuItem";
			this->minAverageDistancesOfEachClassToolStripMenuItem->Size = System::Drawing::Size(261, 22);
			this->minAverageDistancesOfEachClassToolStripMenuItem->Text = L"min average distances of each class";
			this->minAverageDistancesOfEachClassToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::minAverageDistancesOfEachClassToolStripMenuItem_Click);
			// 
			// trainCentroidsToolStripMenuItem
			// 
			this->trainCentroidsToolStripMenuItem->Name = L"trainCentroidsToolStripMenuItem";
			this->trainCentroidsToolStripMenuItem->Size = System::Drawing::Size(261, 22);
			this->trainCentroidsToolStripMenuItem->Text = L"Train Centroids";
			this->trainCentroidsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::trainCentroidsToolStripMenuItem_Click);
			// 
			// testCentroidsToolStripMenuItem
			// 
			this->testCentroidsToolStripMenuItem->Name = L"testCentroidsToolStripMenuItem";
			this->testCentroidsToolStripMenuItem->Size = System::Drawing::Size(261, 22);
			this->testCentroidsToolStripMenuItem->Text = L"Test Centroids";
			this->testCentroidsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testCentroidsToolStripMenuItem_Click);
			// 
			// kNNSumDistamcesToolStripMenuItem
			// 
			this->kNNSumDistamcesToolStripMenuItem->Name = L"kNNSumDistamcesToolStripMenuItem";
			this->kNNSumDistamcesToolStripMenuItem->Size = System::Drawing::Size(261, 22);
			this->kNNSumDistamcesToolStripMenuItem->Text = L"KNN sum Distamces";
			this->kNNSumDistamcesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::kNNSumDistamcesToolStripMenuItem_Click);
			// 
			// trainCentroidUsingMediansToolStripMenuItem
			// 
			this->trainCentroidUsingMediansToolStripMenuItem->Name = L"trainCentroidUsingMediansToolStripMenuItem";
			this->trainCentroidUsingMediansToolStripMenuItem->Size = System::Drawing::Size(261, 22);
			this->trainCentroidUsingMediansToolStripMenuItem->Text = L"Train centroid using medians";
			this->trainCentroidUsingMediansToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::trainCentroidUsingMediansToolStripMenuItem_Click);
			// 
			// testCentroidsUsingMediansToolStripMenuItem
			// 
			this->testCentroidsUsingMediansToolStripMenuItem->Name = L"testCentroidsUsingMediansToolStripMenuItem";
			this->testCentroidsUsingMediansToolStripMenuItem->Size = System::Drawing::Size(261, 22);
			this->testCentroidsUsingMediansToolStripMenuItem->Text = L"Test centroids using medians";
			this->testCentroidsUsingMediansToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testCentroidsUsingMediansToolStripMenuItem_Click);
			// 
			// trainQuartilesToolStripMenuItem
			// 
			this->trainQuartilesToolStripMenuItem->Name = L"trainQuartilesToolStripMenuItem";
			this->trainQuartilesToolStripMenuItem->Size = System::Drawing::Size(261, 22);
			this->trainQuartilesToolStripMenuItem->Text = L"Train quartiles ";
			this->trainQuartilesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::trainQuartilesToolStripMenuItem_Click);
			// 
			// testQuartilesToolStripMenuItem
			// 
			this->testQuartilesToolStripMenuItem->Name = L"testQuartilesToolStripMenuItem";
			this->testQuartilesToolStripMenuItem->Size = System::Drawing::Size(261, 22);
			this->testQuartilesToolStripMenuItem->Text = L"Test Quartiles";
			this->testQuartilesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testQuartilesToolStripMenuItem_Click);
			// 
			// kNNChangeKFrom1ToSqrtTrnsetToolStripMenuItem
			// 
			this->kNNChangeKFrom1ToSqrtTrnsetToolStripMenuItem->Name = L"kNNChangeKFrom1ToSqrtTrnsetToolStripMenuItem";
			this->kNNChangeKFrom1ToSqrtTrnsetToolStripMenuItem->Size = System::Drawing::Size(261, 22);
			this->kNNChangeKFrom1ToSqrtTrnsetToolStripMenuItem->Text = L"KNN change k from 1 to sqrt trnset";
			this->kNNChangeKFrom1ToSqrtTrnsetToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::kNNChangeKFrom1ToSqrtTrnsetToolStripMenuItem_Click);
			// 
			// kNNToolStripMenuItem1
			// 
			this->kNNToolStripMenuItem1->Name = L"kNNToolStripMenuItem1";
			this->kNNToolStripMenuItem1->Size = System::Drawing::Size(261, 22);
			this->kNNToolStripMenuItem1->Text = L"KNN min Sum Dist Fib";
			this->kNNToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::kNNToolStripMenuItem1_Click);
			// 
			// trainBoundariesMedianRowsToolStripMenuItem
			// 
			this->trainBoundariesMedianRowsToolStripMenuItem->Name = L"trainBoundariesMedianRowsToolStripMenuItem";
			this->trainBoundariesMedianRowsToolStripMenuItem->Size = System::Drawing::Size(261, 22);
			this->trainBoundariesMedianRowsToolStripMenuItem->Text = L"train boundaries median rows";
			this->trainBoundariesMedianRowsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::trainBoundariesMedianRowsToolStripMenuItem_Click);
			// 
			// testBoundariesMedianRowsToolStripMenuItem
			// 
			this->testBoundariesMedianRowsToolStripMenuItem->Name = L"testBoundariesMedianRowsToolStripMenuItem";
			this->testBoundariesMedianRowsToolStripMenuItem->Size = System::Drawing::Size(261, 22);
			this->testBoundariesMedianRowsToolStripMenuItem->Text = L"test boundaries median rows";
			this->testBoundariesMedianRowsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testBoundariesMedianRowsToolStripMenuItem_Click);
			// 
			// trainBndryAvgQuartileToolStripMenuItem
			// 
			this->trainBndryAvgQuartileToolStripMenuItem->Name = L"trainBndryAvgQuartileToolStripMenuItem";
			this->trainBndryAvgQuartileToolStripMenuItem->Size = System::Drawing::Size(261, 22);
			this->trainBndryAvgQuartileToolStripMenuItem->Text = L"train bndry avg quartile";
			this->trainBndryAvgQuartileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::trainBndryAvgQuartileToolStripMenuItem_Click);
			// 
			// testBndryAvgQuartileToolStripMenuItem
			// 
			this->testBndryAvgQuartileToolStripMenuItem->Name = L"testBndryAvgQuartileToolStripMenuItem";
			this->testBndryAvgQuartileToolStripMenuItem->Size = System::Drawing::Size(261, 22);
			this->testBndryAvgQuartileToolStripMenuItem->Text = L"test bndry avg quartile";
			this->testBndryAvgQuartileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testBndryAvgQuartileToolStripMenuItem_Click);
			// 
			// testBndryAvgQuarEDToolStripMenuItem
			// 
			this->testBndryAvgQuarEDToolStripMenuItem->Name = L"testBndryAvgQuarEDToolStripMenuItem";
			this->testBndryAvgQuarEDToolStripMenuItem->Size = System::Drawing::Size(261, 22);
			this->testBndryAvgQuarEDToolStripMenuItem->Text = L"test bndry avg quar ED";
			this->testBndryAvgQuarEDToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testBndryAvgQuarEDToolStripMenuItem_Click);
			// 
			// kNNNFoldsToolStripMenuItem
			// 
			this->kNNNFoldsToolStripMenuItem->Name = L"kNNNFoldsToolStripMenuItem";
			this->kNNNFoldsToolStripMenuItem->Size = System::Drawing::Size(261, 22);
			this->kNNNFoldsToolStripMenuItem->Text = L"KNN n folds";
			this->kNNNFoldsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::kNNNFoldsToolStripMenuItem_Click);
			// 
			// kNNNfoldMultiRunsToolStripMenuItem
			// 
			this->kNNNfoldMultiRunsToolStripMenuItem->Name = L"kNNNfoldMultiRunsToolStripMenuItem";
			this->kNNNfoldMultiRunsToolStripMenuItem->Size = System::Drawing::Size(261, 22);
			this->kNNNfoldMultiRunsToolStripMenuItem->Text = L"KNN n-fold multi runs";
			this->kNNNfoldMultiRunsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::kNNNfoldMultiRunsToolStripMenuItem_Click);
			// 
			// kNNAlternativesToolStripMenuItem
			// 
			this->kNNAlternativesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(11) {
				this->nNMajorityToolStripMenuItem,
					this->nNMsxDisMinorityToolStripMenuItem, this->nNToolStripMenuItem, this->trainingAveragesOfSubClassesToolStripMenuItem, this->testAveragesOfSubClassesToolStripMenuItem,
					this->testAverageOfSubClsVotesToolStripMenuItem, this->genaticAlgorithmsToChooseBestExamToolStripMenuItem, this->testGAToolStripMenuItem,
					this->testGANNMajorityToolStripMenuItem, this->trainBestFVsNNAccuracyToolStripMenuItem, this->testTrnBestNNMajorityToolStripMenuItem
			});
			this->kNNAlternativesToolStripMenuItem->Name = L"kNNAlternativesToolStripMenuItem";
			this->kNNAlternativesToolStripMenuItem->Size = System::Drawing::Size(26, 20);
			this->kNNAlternativesToolStripMenuItem->Text = L"p";
			// 
			// nNMajorityToolStripMenuItem
			// 
			this->nNMajorityToolStripMenuItem->Name = L"nNMajorityToolStripMenuItem";
			this->nNMajorityToolStripMenuItem->Size = System::Drawing::Size(241, 22);
			this->nNMajorityToolStripMenuItem->Text = L"NN Majority";
			this->nNMajorityToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::nNMajorityToolStripMenuItem_Click);
			// 
			// nNMsxDisMinorityToolStripMenuItem
			// 
			this->nNMsxDisMinorityToolStripMenuItem->Name = L"nNMsxDisMinorityToolStripMenuItem";
			this->nNMsxDisMinorityToolStripMenuItem->Size = System::Drawing::Size(241, 22);
			this->nNMsxDisMinorityToolStripMenuItem->Text = L"NN max dis Minority";
			this->nNMsxDisMinorityToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::nNMsxDisMinorityToolStripMenuItem_Click);
			// 
			// nNToolStripMenuItem
			// 
			this->nNToolStripMenuItem->Name = L"nNToolStripMenuItem";
			this->nNToolStripMenuItem->Size = System::Drawing::Size(241, 22);
			this->nNToolStripMenuItem->Text = L"NN min max dist avrg";
			this->nNToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::nNToolStripMenuItem_Click);
			// 
			// trainingAveragesOfSubClassesToolStripMenuItem
			// 
			this->trainingAveragesOfSubClassesToolStripMenuItem->Name = L"trainingAveragesOfSubClassesToolStripMenuItem";
			this->trainingAveragesOfSubClassesToolStripMenuItem->Size = System::Drawing::Size(241, 22);
			this->trainingAveragesOfSubClassesToolStripMenuItem->Text = L"Training averages of sub classes";
			this->trainingAveragesOfSubClassesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::trainingAveragesOfSubClassesToolStripMenuItem_Click);
			// 
			// testAveragesOfSubClassesToolStripMenuItem
			// 
			this->testAveragesOfSubClassesToolStripMenuItem->Name = L"testAveragesOfSubClassesToolStripMenuItem";
			this->testAveragesOfSubClassesToolStripMenuItem->Size = System::Drawing::Size(241, 22);
			this->testAveragesOfSubClassesToolStripMenuItem->Text = L"Test averages of sub classes";
			this->testAveragesOfSubClassesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testAveragesOfSubClassesToolStripMenuItem_Click);
			// 
			// testAverageOfSubClsVotesToolStripMenuItem
			// 
			this->testAverageOfSubClsVotesToolStripMenuItem->Name = L"testAverageOfSubClsVotesToolStripMenuItem";
			this->testAverageOfSubClsVotesToolStripMenuItem->Size = System::Drawing::Size(241, 22);
			this->testAverageOfSubClsVotesToolStripMenuItem->Text = L"Test average of sub cls votes";
			this->testAverageOfSubClsVotesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testAverageOfSubClsVotesToolStripMenuItem_Click);
			// 
			// genaticAlgorithmsToChooseBestExamToolStripMenuItem
			// 
			this->genaticAlgorithmsToChooseBestExamToolStripMenuItem->Name = L"genaticAlgorithmsToChooseBestExamToolStripMenuItem";
			this->genaticAlgorithmsToChooseBestExamToolStripMenuItem->Size = System::Drawing::Size(241, 22);
			this->genaticAlgorithmsToChooseBestExamToolStripMenuItem->Text = L"GA train best examples";
			this->genaticAlgorithmsToChooseBestExamToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::genaticAlgorithmsToChooseBestExamToolStripMenuItem_Click);
			// 
			// testGAToolStripMenuItem
			// 
			this->testGAToolStripMenuItem->Name = L"testGAToolStripMenuItem";
			this->testGAToolStripMenuItem->Size = System::Drawing::Size(241, 22);
			this->testGAToolStripMenuItem->Text = L"Test GA knn";
			this->testGAToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testGAToolStripMenuItem_Click);
			// 
			// testGANNMajorityToolStripMenuItem
			// 
			this->testGANNMajorityToolStripMenuItem->Name = L"testGANNMajorityToolStripMenuItem";
			this->testGANNMajorityToolStripMenuItem->Size = System::Drawing::Size(241, 22);
			this->testGANNMajorityToolStripMenuItem->Text = L"Test GA NN Majority";
			this->testGANNMajorityToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testGANNMajorityToolStripMenuItem_Click);
			// 
			// trainBestFVsNNAccuracyToolStripMenuItem
			// 
			this->trainBestFVsNNAccuracyToolStripMenuItem->Name = L"trainBestFVsNNAccuracyToolStripMenuItem";
			this->trainBestFVsNNAccuracyToolStripMenuItem->Size = System::Drawing::Size(241, 22);
			this->trainBestFVsNNAccuracyToolStripMenuItem->Text = L"Train best FVs NN Accuracy";
			this->trainBestFVsNNAccuracyToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::trainBestFVsNNAccuracyToolStripMenuItem_Click);
			// 
			// testTrnBestNNMajorityToolStripMenuItem
			// 
			this->testTrnBestNNMajorityToolStripMenuItem->Name = L"testTrnBestNNMajorityToolStripMenuItem";
			this->testTrnBestNNMajorityToolStripMenuItem->Size = System::Drawing::Size(241, 22);
			this->testTrnBestNNMajorityToolStripMenuItem->Text = L"Test Trn best NN Majority";
			this->testTrnBestNNMajorityToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testTrnBestNNMajorityToolStripMenuItem_Click);
			// 
			// weightsToolStripMenuItem
			// 
			this->weightsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->trainWeightsUsingChiToolStripMenuItem,
					this->trainWeightUsingNNToolStripMenuItem, this->trainUsingMinimumDistanceToGetBoundaryPointsToolStripMenuItem, this->testMDBPToolStripMenuItem,
					this->trainGAOfNonZeroMDBPToolStripMenuItem, this->testGAMDBPToolStripMenuItem
			});
			this->weightsToolStripMenuItem->Name = L"weightsToolStripMenuItem";
			this->weightsToolStripMenuItem->Size = System::Drawing::Size(60, 20);
			this->weightsToolStripMenuItem->Text = L"weights";
			// 
			// trainWeightsUsingChiToolStripMenuItem
			// 
			this->trainWeightsUsingChiToolStripMenuItem->Name = L"trainWeightsUsingChiToolStripMenuItem";
			this->trainWeightsUsingChiToolStripMenuItem->Size = System::Drawing::Size(357, 22);
			this->trainWeightsUsingChiToolStripMenuItem->Text = L"train weights using Chi";
			this->trainWeightsUsingChiToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::trainWeightsUsingChiToolStripMenuItem_Click);
			// 
			// trainWeightUsingNNToolStripMenuItem
			// 
			this->trainWeightUsingNNToolStripMenuItem->Name = L"trainWeightUsingNNToolStripMenuItem";
			this->trainWeightUsingNNToolStripMenuItem->Size = System::Drawing::Size(357, 22);
			this->trainWeightUsingNNToolStripMenuItem->Text = L"train weight using NN accuracy";
			this->trainWeightUsingNNToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::trainWeightUsingNNToolStripMenuItem_Click);
			// 
			// trainUsingMinimumDistanceToGetBoundaryPointsToolStripMenuItem
			// 
			this->trainUsingMinimumDistanceToGetBoundaryPointsToolStripMenuItem->Name = L"trainUsingMinimumDistanceToGetBoundaryPointsToolStripMenuItem";
			this->trainUsingMinimumDistanceToGetBoundaryPointsToolStripMenuItem->Size = System::Drawing::Size(357, 22);
			this->trainUsingMinimumDistanceToGetBoundaryPointsToolStripMenuItem->Text = L"train using minimum distance to get boundary points";
			this->trainUsingMinimumDistanceToGetBoundaryPointsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::trainUsingMinimumDistanceToGetBoundaryPointsToolStripMenuItem_Click);
			// 
			// testMDBPToolStripMenuItem
			// 
			this->testMDBPToolStripMenuItem->Name = L"testMDBPToolStripMenuItem";
			this->testMDBPToolStripMenuItem->Size = System::Drawing::Size(357, 22);
			this->testMDBPToolStripMenuItem->Text = L"test MDBP";
			this->testMDBPToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testMDBPToolStripMenuItem_Click);
			// 
			// trainGAOfNonZeroMDBPToolStripMenuItem
			// 
			this->trainGAOfNonZeroMDBPToolStripMenuItem->Name = L"trainGAOfNonZeroMDBPToolStripMenuItem";
			this->trainGAOfNonZeroMDBPToolStripMenuItem->Size = System::Drawing::Size(357, 22);
			this->trainGAOfNonZeroMDBPToolStripMenuItem->Text = L"train GA of Non zero MDBP";
			this->trainGAOfNonZeroMDBPToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::trainGAOfNonZeroMDBPToolStripMenuItem_Click);
			// 
			// testGAMDBPToolStripMenuItem
			// 
			this->testGAMDBPToolStripMenuItem->Name = L"testGAMDBPToolStripMenuItem";
			this->testGAMDBPToolStripMenuItem->Size = System::Drawing::Size(357, 22);
			this->testGAMDBPToolStripMenuItem->Text = L"Test GAMDBP";
			this->testGAMDBPToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testGAMDBPToolStripMenuItem_Click);
			// 
			// newToolStripMenuItem
			// 
			this->newToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->kNNChangeKFrom1ToSqrtNOddKsToolStripMenuItem,
					this->kNNChangeKFrom1ToSqrtNOddKsWeightsToolStripMenuItem, this->kNNChangeKFrom1ToSqrtNKsWeightsToolStripMenuItem, this->kNNChangeKFrom1ToSqrtNKsWeightsWithIINdxToolStripMenuItem,
					this->invertedIndexToolStripMenuItem, this->kNFToolStripMenuItem, this->ensimbleIINCToolStripMenuItem
			});
			this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
			this->newToolStripMenuItem->Size = System::Drawing::Size(102, 20);
			this->newToolStripMenuItem->Text = L"new getred of K";
			// 
			// kNNChangeKFrom1ToSqrtNOddKsToolStripMenuItem
			// 
			this->kNNChangeKFrom1ToSqrtNOddKsToolStripMenuItem->Name = L"kNNChangeKFrom1ToSqrtNOddKsToolStripMenuItem";
			this->kNNChangeKFrom1ToSqrtNOddKsToolStripMenuItem->Size = System::Drawing::Size(349, 22);
			this->kNNChangeKFrom1ToSqrtNOddKsToolStripMenuItem->Text = L"KNN change k from 1 to sqrt n odd ks";
			this->kNNChangeKFrom1ToSqrtNOddKsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::kNNChangeKFrom1ToSqrtNOddKsToolStripMenuItem_Click);
			// 
			// kNNChangeKFrom1ToSqrtNOddKsWeightsToolStripMenuItem
			// 
			this->kNNChangeKFrom1ToSqrtNOddKsWeightsToolStripMenuItem->Name = L"kNNChangeKFrom1ToSqrtNOddKsWeightsToolStripMenuItem";
			this->kNNChangeKFrom1ToSqrtNOddKsWeightsToolStripMenuItem->Size = System::Drawing::Size(349, 22);
			this->kNNChangeKFrom1ToSqrtNOddKsWeightsToolStripMenuItem->Text = L"KNN change k from 1 to sqrt n odd ks weights";
			this->kNNChangeKFrom1ToSqrtNOddKsWeightsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::kNNChangeKFrom1ToSqrtNOddKsWeightsToolStripMenuItem_Click);
			// 
			// kNNChangeKFrom1ToSqrtNKsWeightsToolStripMenuItem
			// 
			this->kNNChangeKFrom1ToSqrtNKsWeightsToolStripMenuItem->Name = L"kNNChangeKFrom1ToSqrtNKsWeightsToolStripMenuItem";
			this->kNNChangeKFrom1ToSqrtNKsWeightsToolStripMenuItem->Size = System::Drawing::Size(349, 22);
			this->kNNChangeKFrom1ToSqrtNKsWeightsToolStripMenuItem->Text = L"KNN change k from 1 to sqrt n ks weights";
			this->kNNChangeKFrom1ToSqrtNKsWeightsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::kNNChangeKFrom1ToSqrtNKsWeightsToolStripMenuItem_Click);
			// 
			// kNNChangeKFrom1ToSqrtNKsWeightsWithIINdxToolStripMenuItem
			// 
			this->kNNChangeKFrom1ToSqrtNKsWeightsWithIINdxToolStripMenuItem->Name = L"kNNChangeKFrom1ToSqrtNKsWeightsWithIINdxToolStripMenuItem";
			this->kNNChangeKFrom1ToSqrtNKsWeightsWithIINdxToolStripMenuItem->Size = System::Drawing::Size(349, 22);
			this->kNNChangeKFrom1ToSqrtNKsWeightsWithIINdxToolStripMenuItem->Text = L"KNN change k from 1 to sqrt n ks weights with IINdx";
			this->kNNChangeKFrom1ToSqrtNKsWeightsWithIINdxToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::kNNChangeKFrom1ToSqrtNKsWeightsWithIINdxToolStripMenuItem_Click);
			// 
			// invertedIndexToolStripMenuItem
			// 
			this->invertedIndexToolStripMenuItem->Name = L"invertedIndexToolStripMenuItem";
			this->invertedIndexToolStripMenuItem->Size = System::Drawing::Size(349, 22);
			this->invertedIndexToolStripMenuItem->Text = L"inverted index";
			this->invertedIndexToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::invertedIndexToolStripMenuItem_Click);
			// 
			// kNFToolStripMenuItem
			// 
			this->kNFToolStripMenuItem->Name = L"kNFToolStripMenuItem";
			this->kNFToolStripMenuItem->Size = System::Drawing::Size(349, 22);
			this->kNFToolStripMenuItem->Text = L"KNF";
			this->kNFToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::kNFToolStripMenuItem_Click);
			// 
			// ensimbleIINCToolStripMenuItem
			// 
			this->ensimbleIINCToolStripMenuItem->Name = L"ensimbleIINCToolStripMenuItem";
			this->ensimbleIINCToolStripMenuItem->Size = System::Drawing::Size(349, 22);
			this->ensimbleIINCToolStripMenuItem->Text = L"ensimble IINC";
			this->ensimbleIINCToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::ensimbleIINCToolStripMenuItem_Click);
			// 
			// cpmprehinsiveTestsToolStripMenuItem
			// 
			this->cpmprehinsiveTestsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->testKnnWithDifferenToolStripMenuItem,
					this->testKnnWithDifferentKToolStripMenuItem, this->testIINCOnAllDatasetsToolStripMenuItem, this->testKNNChangeKFrom1ToSqrtNOddWeightsToolStripMenuItem,
					this->testKNNChangeKFrom1ToHalfSqrtNOddWeightsToolStripMenuItem, this->testKNNKfrom1ToSrtnOddWeightsNewToolStripMenuItem, this->testKnnWithK304560ToolStripMenuItem,
					this->knnOddEightsNewWithDistanceToolStripMenuItem
			});
			this->cpmprehinsiveTestsToolStripMenuItem->Name = L"cpmprehinsiveTestsToolStripMenuItem";
			this->cpmprehinsiveTestsToolStripMenuItem->Size = System::Drawing::Size(26, 20);
			this->cpmprehinsiveTestsToolStripMenuItem->Text = L"t ";
			// 
			// testKnnWithDifferenToolStripMenuItem
			// 
			this->testKnnWithDifferenToolStripMenuItem->Name = L"testKnnWithDifferenToolStripMenuItem";
			this->testKnnWithDifferenToolStripMenuItem->Size = System::Drawing::Size(349, 22);
			this->testKnnWithDifferenToolStripMenuItem->Text = L"test knn with differenent distances on all datasets";
			this->testKnnWithDifferenToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testKnnWithDifferenToolStripMenuItem_Click);
			// 
			// testKnnWithDifferentKToolStripMenuItem
			// 
			this->testKnnWithDifferentKToolStripMenuItem->Name = L"testKnnWithDifferentKToolStripMenuItem";
			this->testKnnWithDifferentKToolStripMenuItem->Size = System::Drawing::Size(349, 22);
			this->testKnnWithDifferentKToolStripMenuItem->Text = L"test Knn with different K";
			this->testKnnWithDifferentKToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testKnnWithDifferentKToolStripMenuItem_Click);
			// 
			// testIINCOnAllDatasetsToolStripMenuItem
			// 
			this->testIINCOnAllDatasetsToolStripMenuItem->Name = L"testIINCOnAllDatasetsToolStripMenuItem";
			this->testIINCOnAllDatasetsToolStripMenuItem->Size = System::Drawing::Size(349, 22);
			this->testIINCOnAllDatasetsToolStripMenuItem->Text = L"Test IINC on all datasets";
			this->testIINCOnAllDatasetsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testIINCOnAllDatasetsToolStripMenuItem_Click);
			// 
			// testKNNChangeKFrom1ToSqrtNOddWeightsToolStripMenuItem
			// 
			this->testKNNChangeKFrom1ToSqrtNOddWeightsToolStripMenuItem->Name = L"testKNNChangeKFrom1ToSqrtNOddWeightsToolStripMenuItem";
			this->testKNNChangeKFrom1ToSqrtNOddWeightsToolStripMenuItem->Size = System::Drawing::Size(349, 22);
			this->testKNNChangeKFrom1ToSqrtNOddWeightsToolStripMenuItem->Text = L"Test KNN change k from 1 to sqrtN odd weights";
			this->testKNNChangeKFrom1ToSqrtNOddWeightsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testKNNChangeKFrom1ToSqrtNOddWeightsToolStripMenuItem_Click);
			// 
			// testKNNChangeKFrom1ToHalfSqrtNOddWeightsToolStripMenuItem
			// 
			this->testKNNChangeKFrom1ToHalfSqrtNOddWeightsToolStripMenuItem->Name = L"testKNNChangeKFrom1ToHalfSqrtNOddWeightsToolStripMenuItem";
			this->testKNNChangeKFrom1ToHalfSqrtNOddWeightsToolStripMenuItem->Size = System::Drawing::Size(349, 22);
			this->testKNNChangeKFrom1ToHalfSqrtNOddWeightsToolStripMenuItem->Text = L"Test KNN change k from 1 to half sqrtN odd weights";
			this->testKNNChangeKFrom1ToHalfSqrtNOddWeightsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testKNNChangeKFrom1ToHalfSqrtNOddWeightsToolStripMenuItem_Click);
			// 
			// testKNNKfrom1ToSrtnOddWeightsNewToolStripMenuItem
			// 
			this->testKNNKfrom1ToSrtnOddWeightsNewToolStripMenuItem->Name = L"testKNNKfrom1ToSrtnOddWeightsNewToolStripMenuItem";
			this->testKNNKfrom1ToSrtnOddWeightsNewToolStripMenuItem->Size = System::Drawing::Size(349, 22);
			this->testKNNKfrom1ToSrtnOddWeightsNewToolStripMenuItem->Text = L"test KNN kfrom 1 to srtn odd weights new";
			this->testKNNKfrom1ToSrtnOddWeightsNewToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testKNNKfrom1ToSrtnOddWeightsNewToolStripMenuItem_Click);
			// 
			// testKnnWithK304560ToolStripMenuItem
			// 
			this->testKnnWithK304560ToolStripMenuItem->Name = L"testKnnWithK304560ToolStripMenuItem";
			this->testKnnWithK304560ToolStripMenuItem->Size = System::Drawing::Size(349, 22);
			this->testKnnWithK304560ToolStripMenuItem->Text = L"test Knn with k 30 45 60";
			this->testKnnWithK304560ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testKnnWithK304560ToolStripMenuItem_Click);
			// 
			// knnOddEightsNewWithDistanceToolStripMenuItem
			// 
			this->knnOddEightsNewWithDistanceToolStripMenuItem->Name = L"knnOddEightsNewWithDistanceToolStripMenuItem";
			this->knnOddEightsNewWithDistanceToolStripMenuItem->Size = System::Drawing::Size(349, 22);
			this->knnOddEightsNewWithDistanceToolStripMenuItem->Text = L"knn odd eights new with distance";
			this->knnOddEightsNewWithDistanceToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::knnOddEightsNewWithDistanceToolStripMenuItem_Click);
			// 
			// normsToolStripMenuItem
			// 
			this->normsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->eDNormBinsearchKNNToolStripMenuItem,
					this->normBinsearchKnnDivByComplementToolStripMenuItem, this->kNNWithBaggingToolStripMenuItem, this->train01NormsBtreeToolStripMenuItem,
					this->test01NormsBtreeNNToolStripMenuItem, this->test01NormsBtreeWithLognExamplesToolStripMenuItem, this->te
			});
			this->normsToolStripMenuItem->Name = L"normsToolStripMenuItem";
			this->normsToolStripMenuItem->Size = System::Drawing::Size(55, 20);
			this->normsToolStripMenuItem->Text = L"Norms";
			// 
			// eDNormBinsearchKNNToolStripMenuItem
			// 
			this->eDNormBinsearchKNNToolStripMenuItem->Name = L"eDNormBinsearchKNNToolStripMenuItem";
			this->eDNormBinsearchKNNToolStripMenuItem->Size = System::Drawing::Size(286, 22);
			this->eDNormBinsearchKNNToolStripMenuItem->Text = L"ED norm Binsearch KNN";
			this->eDNormBinsearchKNNToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::eDNormBinsearchKNNToolStripMenuItem_Click);
			// 
			// normBinsearchKnnDivByComplementToolStripMenuItem
			// 
			this->normBinsearchKnnDivByComplementToolStripMenuItem->Name = L"normBinsearchKnnDivByComplementToolStripMenuItem";
			this->normBinsearchKnnDivByComplementToolStripMenuItem->Size = System::Drawing::Size(286, 22);
			this->normBinsearchKnnDivByComplementToolStripMenuItem->Text = L"norm binsearch knn div by complement";
			this->normBinsearchKnnDivByComplementToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::normBinsearchKnnDivByComplementToolStripMenuItem_Click);
			// 
			// kNNWithBaggingToolStripMenuItem
			// 
			this->kNNWithBaggingToolStripMenuItem->Name = L"kNNWithBaggingToolStripMenuItem";
			this->kNNWithBaggingToolStripMenuItem->Size = System::Drawing::Size(286, 22);
			this->kNNWithBaggingToolStripMenuItem->Text = L"KNN with bagging";
			this->kNNWithBaggingToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::kNNWithBaggingToolStripMenuItem_Click);
			// 
			// train01NormsBtreeToolStripMenuItem
			// 
			this->train01NormsBtreeToolStripMenuItem->Name = L"train01NormsBtreeToolStripMenuItem";
			this->train01NormsBtreeToolStripMenuItem->Size = System::Drawing::Size(286, 22);
			this->train01NormsBtreeToolStripMenuItem->Text = L"Train 01Norms Btree";
			this->train01NormsBtreeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::train01NormsBtreeToolStripMenuItem_Click);
			// 
			// test01NormsBtreeNNToolStripMenuItem
			// 
			this->test01NormsBtreeNNToolStripMenuItem->Name = L"test01NormsBtreeNNToolStripMenuItem";
			this->test01NormsBtreeNNToolStripMenuItem->Size = System::Drawing::Size(286, 22);
			this->test01NormsBtreeNNToolStripMenuItem->Text = L"Test 01Norms Btree NN";
			this->test01NormsBtreeNNToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::test01NormsBtreeNNToolStripMenuItem_Click);
			// 
			// test01NormsBtreeWithLognExamplesToolStripMenuItem
			// 
			this->test01NormsBtreeWithLognExamplesToolStripMenuItem->Name = L"test01NormsBtreeWithLognExamplesToolStripMenuItem";
			this->test01NormsBtreeWithLognExamplesToolStripMenuItem->Size = System::Drawing::Size(286, 22);
			this->test01NormsBtreeWithLognExamplesToolStripMenuItem->Text = L"Test 01Norms Btree with logn examples";
			this->test01NormsBtreeWithLognExamplesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::test01NormsBtreeWithLognExamplesToolStripMenuItem_Click);
			// 
			// te
			// 
			this->te->Name = L"te";
			this->te->Size = System::Drawing::Size(286, 22);
			this->te->Text = L"Test 01norms Btree with 2log examples";
			this->te->Click += gcnew System::EventHandler(this, &Form1::test01normsBtreeWith2logExamplesToolStripMenuItem_Click);
			// 
			// clusteringToolStripMenuItem
			// 
			this->clusteringToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->kmeanToolStripMenuItem,
					this->kmeanHasDistToolStripMenuItem, this->testToolStripMenuItem1
			});
			this->clusteringToolStripMenuItem->Name = L"clusteringToolStripMenuItem";
			this->clusteringToolStripMenuItem->Size = System::Drawing::Size(73, 20);
			this->clusteringToolStripMenuItem->Text = L"Clustering";
			// 
			// kmeanToolStripMenuItem
			// 
			this->kmeanToolStripMenuItem->Name = L"kmeanToolStripMenuItem";
			this->kmeanToolStripMenuItem->Size = System::Drawing::Size(159, 22);
			this->kmeanToolStripMenuItem->Text = L"K-mean";
			this->kmeanToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::kmeanToolStripMenuItem_Click);
			// 
			// kmeanHasDistToolStripMenuItem
			// 
			this->kmeanHasDistToolStripMenuItem->Name = L"kmeanHasDistToolStripMenuItem";
			this->kmeanHasDistToolStripMenuItem->Size = System::Drawing::Size(159, 22);
			this->kmeanHasDistToolStripMenuItem->Text = L"K-mean HasDist";
			this->kmeanHasDistToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::kmeanHasDistToolStripMenuItem_Click);
			// 
			// testToolStripMenuItem1
			// 
			this->testToolStripMenuItem1->Name = L"testToolStripMenuItem1";
			this->testToolStripMenuItem1->Size = System::Drawing::Size(159, 22);
			this->testToolStripMenuItem1->Text = L"test";
			this->testToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::testToolStripMenuItem1_Click);
			// 
			// farthestDistancesToolStripMenuItem
			// 
			this->farthestDistancesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->bFFarthestDistanceToolStripMenuItem });
			this->farthestDistancesToolStripMenuItem->Name = L"farthestDistancesToolStripMenuItem";
			this->farthestDistancesToolStripMenuItem->Size = System::Drawing::Size(113, 20);
			this->farthestDistancesToolStripMenuItem->Text = L"Farthest distances";
			// 
			// bFFarthestDistanceToolStripMenuItem
			// 
			this->bFFarthestDistanceToolStripMenuItem->Name = L"bFFarthestDistanceToolStripMenuItem";
			this->bFFarthestDistanceToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->bFFarthestDistanceToolStripMenuItem->Text = L"BF farthest distance";
			this->bFFarthestDistanceToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::bFFarthestDistanceToolStripMenuItem_Click);
			// 
			// tree2RndpntToolStripMenuItem
			// 
			this->tree2RndpntToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(12) {
				this->testALLWithNFoldEfficientToolStripMenuItem,
					this->trainBtreeToolStripMenuItem, this->testTreeToLeafToolStripMenuItem, this->testTreeToKlognToolStripMenuItem, this->trainBtr2pMinMaxNormToolStripMenuItem,
					this->testTree2pmnmxToLeafToolStripMenuItem, this->testAllWithNFoldToolStripMenuItem, this->testAllOnReadyTrainAndTestToolStripMenuItem,
					this->trainBST2ExtremPointsToolStripMenuItem, this->testBST2ExtremPointsToolStripMenuItem, this->trainFurthestPBSTToolStripMenuItem,
					this->testFurthestPBSTToolStripMenuItem
			});
			this->tree2RndpntToolStripMenuItem->Name = L"tree2RndpntToolStripMenuItem";
			this->tree2RndpntToolStripMenuItem->Size = System::Drawing::Size(86, 20);
			this->tree2RndpntToolStripMenuItem->Text = L"Tree2Rndpnt";
			// 
			// testALLWithNFoldEfficientToolStripMenuItem
			// 
			this->testALLWithNFoldEfficientToolStripMenuItem->Name = L"testALLWithNFoldEfficientToolStripMenuItem";
			this->testALLWithNFoldEfficientToolStripMenuItem->Size = System::Drawing::Size(236, 22);
			this->testALLWithNFoldEfficientToolStripMenuItem->Text = L"Test ALL with n fold Efficient";
			this->testALLWithNFoldEfficientToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testALLWithNFoldEfficientToolStripMenuItem_Click);
			// 
			// trainBtreeToolStripMenuItem
			// 
			this->trainBtreeToolStripMenuItem->Name = L"trainBtreeToolStripMenuItem";
			this->trainBtreeToolStripMenuItem->Size = System::Drawing::Size(236, 22);
			this->trainBtreeToolStripMenuItem->Text = L"Train Btree2RndPts";
			this->trainBtreeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::trainBtreeToolStripMenuItem_Click);
			// 
			// testTreeToLeafToolStripMenuItem
			// 
			this->testTreeToLeafToolStripMenuItem->Name = L"testTreeToLeafToolStripMenuItem";
			this->testTreeToLeafToolStripMenuItem->Size = System::Drawing::Size(236, 22);
			this->testTreeToLeafToolStripMenuItem->Text = L"Test Tree to leaf";
			this->testTreeToLeafToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testTreeToLeafToolStripMenuItem_Click);
			// 
			// testTreeToKlognToolStripMenuItem
			// 
			this->testTreeToKlognToolStripMenuItem->Name = L"testTreeToKlognToolStripMenuItem";
			this->testTreeToKlognToolStripMenuItem->Size = System::Drawing::Size(236, 22);
			this->testTreeToKlognToolStripMenuItem->Text = L"Test Tree to klogn";
			this->testTreeToKlognToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testTreeToKlognToolStripMenuItem_Click);
			// 
			// trainBtr2pMinMaxNormToolStripMenuItem
			// 
			this->trainBtr2pMinMaxNormToolStripMenuItem->Name = L"trainBtr2pMinMaxNormToolStripMenuItem";
			this->trainBtr2pMinMaxNormToolStripMenuItem->Size = System::Drawing::Size(236, 22);
			this->trainBtr2pMinMaxNormToolStripMenuItem->Text = L"Train Btr2pMinMaxNorm";
			this->trainBtr2pMinMaxNormToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::trainBtr2pMinMaxNormToolStripMenuItem_Click);
			// 
			// testTree2pmnmxToLeafToolStripMenuItem
			// 
			this->testTree2pmnmxToLeafToolStripMenuItem->Name = L"testTree2pmnmxToLeafToolStripMenuItem";
			this->testTree2pmnmxToLeafToolStripMenuItem->Size = System::Drawing::Size(236, 22);
			this->testTree2pmnmxToLeafToolStripMenuItem->Text = L"Test Tree2pmnmx to leaf";
			this->testTree2pmnmxToLeafToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testTree2pmnmxToLeafToolStripMenuItem_Click);
			// 
			// testAllWithNFoldToolStripMenuItem
			// 
			this->testAllWithNFoldToolStripMenuItem->Name = L"testAllWithNFoldToolStripMenuItem";
			this->testAllWithNFoldToolStripMenuItem->Size = System::Drawing::Size(236, 22);
			this->testAllWithNFoldToolStripMenuItem->Text = L"Test All with n fold";
			this->testAllWithNFoldToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testAllWithNFoldToolStripMenuItem_Click);
			// 
			// testAllOnReadyTrainAndTestToolStripMenuItem
			// 
			this->testAllOnReadyTrainAndTestToolStripMenuItem->Name = L"testAllOnReadyTrainAndTestToolStripMenuItem";
			this->testAllOnReadyTrainAndTestToolStripMenuItem->Size = System::Drawing::Size(236, 22);
			this->testAllOnReadyTrainAndTestToolStripMenuItem->Text = L"Test All on Ready train and test";
			this->testAllOnReadyTrainAndTestToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testAllOnReadyTrainAndTestToolStripMenuItem_Click);
			// 
			// trainBST2ExtremPointsToolStripMenuItem
			// 
			this->trainBST2ExtremPointsToolStripMenuItem->Name = L"trainBST2ExtremPointsToolStripMenuItem";
			this->trainBST2ExtremPointsToolStripMenuItem->Size = System::Drawing::Size(236, 22);
			this->trainBST2ExtremPointsToolStripMenuItem->Text = L"Train BST 2Extrem Points";
			this->trainBST2ExtremPointsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::trainBST2ExtremPointsToolStripMenuItem_Click);
			// 
			// testBST2ExtremPointsToolStripMenuItem
			// 
			this->testBST2ExtremPointsToolStripMenuItem->Name = L"testBST2ExtremPointsToolStripMenuItem";
			this->testBST2ExtremPointsToolStripMenuItem->Size = System::Drawing::Size(236, 22);
			this->testBST2ExtremPointsToolStripMenuItem->Text = L"Test BST 2Extrem Points";
			this->testBST2ExtremPointsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testBST2ExtremPointsToolStripMenuItem_Click);
			// 
			// trainFurthestPBSTToolStripMenuItem
			// 
			this->trainFurthestPBSTToolStripMenuItem->Name = L"trainFurthestPBSTToolStripMenuItem";
			this->trainFurthestPBSTToolStripMenuItem->Size = System::Drawing::Size(236, 22);
			this->trainFurthestPBSTToolStripMenuItem->Text = L"TrainFurthestP BST";
			this->trainFurthestPBSTToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::trainFurthestPBSTToolStripMenuItem_Click);
			// 
			// testFurthestPBSTToolStripMenuItem
			// 
			this->testFurthestPBSTToolStripMenuItem->Name = L"testFurthestPBSTToolStripMenuItem";
			this->testFurthestPBSTToolStripMenuItem->Size = System::Drawing::Size(236, 22);
			this->testFurthestPBSTToolStripMenuItem->Text = L"Test FurthestP BST";
			this->testFurthestPBSTToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testFurthestPBSTToolStripMenuItem_Click);
			// 
			// multiTreesToolStripMenuItem
			// 
			this->multiTreesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->normBTreePerClassToolStripMenuItem,
					this->testNormBtreePerClassToolStripMenuItem
			});
			this->multiTreesToolStripMenuItem->Name = L"multiTreesToolStripMenuItem";
			this->multiTreesToolStripMenuItem->Size = System::Drawing::Size(75, 20);
			this->multiTreesToolStripMenuItem->Text = L"Multi trees";
			// 
			// normBTreePerClassToolStripMenuItem
			// 
			this->normBTreePerClassToolStripMenuItem->Name = L"normBTreePerClassToolStripMenuItem";
			this->normBTreePerClassToolStripMenuItem->Size = System::Drawing::Size(203, 22);
			this->normBTreePerClassToolStripMenuItem->Text = L"Norm BTreePerClass";
			this->normBTreePerClassToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::normBTreePerClassToolStripMenuItem_Click);
			// 
			// testNormBtreePerClassToolStripMenuItem
			// 
			this->testNormBtreePerClassToolStripMenuItem->Name = L"testNormBtreePerClassToolStripMenuItem";
			this->testNormBtreePerClassToolStripMenuItem->Size = System::Drawing::Size(203, 22);
			this->testNormBtreePerClassToolStripMenuItem->Text = L"Test Norm BtreePerClass";
			this->testNormBtreePerClassToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testNormBtreePerClassToolStripMenuItem_Click);
			// 
			// decsionTreesToolStripMenuItem
			// 
			this->decsionTreesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->furthestPointDTToolStripMenuItem,
					this->testFurthesPointDTToolStripMenuItem, this->randomMinMaxClassDTToolStripMenuItem, this->testRandomMinMaxClassDTToolStripMenuItem
			});
			this->decsionTreesToolStripMenuItem->Name = L"decsionTreesToolStripMenuItem";
			this->decsionTreesToolStripMenuItem->Size = System::Drawing::Size(89, 20);
			this->decsionTreesToolStripMenuItem->Text = L"Decsion trees";
			// 
			// furthestPointDTToolStripMenuItem
			// 
			this->furthestPointDTToolStripMenuItem->Name = L"furthestPointDTToolStripMenuItem";
			this->furthestPointDTToolStripMenuItem->Size = System::Drawing::Size(237, 22);
			this->furthestPointDTToolStripMenuItem->Text = L"Furthest Point DT";
			this->furthestPointDTToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::furthestPointDTToolStripMenuItem_Click);
			// 
			// testFurthesPointDTToolStripMenuItem
			// 
			this->testFurthesPointDTToolStripMenuItem->Name = L"testFurthesPointDTToolStripMenuItem";
			this->testFurthesPointDTToolStripMenuItem->Size = System::Drawing::Size(237, 22);
			this->testFurthesPointDTToolStripMenuItem->Text = L"Test Furthes Point DT";
			this->testFurthesPointDTToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testFurthesPointDTToolStripMenuItem_Click);
			// 
			// randomMinMaxClassDTToolStripMenuItem
			// 
			this->randomMinMaxClassDTToolStripMenuItem->Name = L"randomMinMaxClassDTToolStripMenuItem";
			this->randomMinMaxClassDTToolStripMenuItem->Size = System::Drawing::Size(237, 22);
			this->randomMinMaxClassDTToolStripMenuItem->Text = L"Random min max class DT";
			this->randomMinMaxClassDTToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::randomMinMaxClassDTToolStripMenuItem_Click);
			// 
			// testRandomMinMaxClassDTToolStripMenuItem
			// 
			this->testRandomMinMaxClassDTToolStripMenuItem->Name = L"testRandomMinMaxClassDTToolStripMenuItem";
			this->testRandomMinMaxClassDTToolStripMenuItem->Size = System::Drawing::Size(237, 22);
			this->testRandomMinMaxClassDTToolStripMenuItem->Text = L"Test Random min max class DT";
			this->testRandomMinMaxClassDTToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testRandomMinMaxClassDTToolStripMenuItem_Click);
			// 
			// cBIRToolStripMenuItem
			// 
			this->cBIRToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->indextraindatUsing2FPBSTToolStripMenuItem,
					this->testIndexToolStripMenuItem
			});
			this->cBIRToolStripMenuItem->Name = L"cBIRToolStripMenuItem";
			this->cBIRToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->cBIRToolStripMenuItem->Text = L"CBIR";
			// 
			// indextraindatUsing2FPBSTToolStripMenuItem
			// 
			this->indextraindatUsing2FPBSTToolStripMenuItem->Name = L"indextraindatUsing2FPBSTToolStripMenuItem";
			this->indextraindatUsing2FPBSTToolStripMenuItem->Size = System::Drawing::Size(226, 22);
			this->indextraindatUsing2FPBSTToolStripMenuItem->Text = L"index train dat using 2FP BST";
			this->indextraindatUsing2FPBSTToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::indextraindatUsing2FPBSTToolStripMenuItem_Click);
			// 
			// testIndexToolStripMenuItem
			// 
			this->testIndexToolStripMenuItem->Name = L"testIndexToolStripMenuItem";
			this->testIndexToolStripMenuItem->Size = System::Drawing::Size(226, 22);
			this->testIndexToolStripMenuItem->Text = L"Test Index";
			this->testIndexToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testIndexToolStripMenuItem_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(12, 95);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(422, 363);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(24, 79);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Train file";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(488, 95);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(418, 363);
			this->richTextBox2->TabIndex = 3;
			this->richTextBox2->Text = L"";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(655, 79);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Test file";
			// 
			// statusStrip1
			// 
			this->statusStrip1->Location = System::Drawing::Point(0, 541);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(1096, 22);
			this->statusStrip1->TabIndex = 5;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(16, 463);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 13);
			this->label3->TabIndex = 6;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(86, 481);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Clear";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(831, 485);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Clear";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(583, 485);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(40, 20);
			this->textBox1->TabIndex = 9;
			this->textBox1->Text = L"0.34";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(485, 490);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(95, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"test to train ration";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(629, 483);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(129, 23);
			this->button3->TabIndex = 11;
			this->button3->Text = L"create test set";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// richTextBox3
			// 
			this->richTextBox3->Location = System::Drawing::Point(440, 95);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(42, 363);
			this->richTextBox3->TabIndex = 12;
			this->richTextBox3->Text = L"";
			// 
			// richTextBox4
			// 
			this->richTextBox4->Location = System::Drawing::Point(912, 95);
			this->richTextBox4->Name = L"richTextBox4";
			this->richTextBox4->Size = System::Drawing::Size(42, 363);
			this->richTextBox4->TabIndex = 13;
			this->richTextBox4->Text = L"";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(451, 79);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(55, 13);
			this->label5->TabIndex = 14;
			this->label5->Text = L"train class";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(909, 79);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(52, 13);
			this->label6->TabIndex = 15;
			this->label6->Text = L"test class";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(583, 514);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(40, 20);
			this->textBox2->TabIndex = 16;
			this->textBox2->Text = L"1";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(563, 521);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(13, 13);
			this->label7->TabIndex = 17;
			this->label7->Text = L"K";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(764, 521);
			this->label8->MaximumSize = System::Drawing::Size(1000, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(41, 13);
			this->label8->TabIndex = 18;
			this->label8->Text = L"Result:";
			// 
			// richTextBox5
			// 
			this->richTextBox5->Location = System::Drawing::Point(978, 95);
			this->richTextBox5->Name = L"richTextBox5";
			this->richTextBox5->Size = System::Drawing::Size(42, 363);
			this->richTextBox5->TabIndex = 19;
			this->richTextBox5->Text = L"";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(629, 512);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(129, 23);
			this->button4->TabIndex = 21;
			this->button4->Text = L"Swap Train Test";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"ED", L"Weighted ED", L"Manhaten", L"Hausdorff",
					L"Hassanat", L"Tanh", L"abs/range//Wave hedges", L"New Hassanat Dist (not working)", L"AbsDifRate", L"1-1/exp(abs(Ai-Bi)"
			});
			this->comboBox1->Location = System::Drawing::Point(54, 42);
			this->comboBox1->MaxDropDownItems = 20;
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(148, 21);
			this->comboBox1->TabIndex = 22;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(0, 42);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(48, 13);
			this->label10->TabIndex = 23;
			this->label10->Text = L"Distance";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(30, 507);
			this->progressBar1->Maximum = 1000000;
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(231, 23);
			this->progressBar1->Step = 1;
			this->progressBar1->TabIndex = 24;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(232, 42);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(72, 17);
			this->checkBox1->TabIndex = 25;
			this->checkBox1->Text = L"Normalize";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(378, 45);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(40, 20);
			this->textBox3->TabIndex = 26;
			this->textBox3->Text = L"0.50";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(310, 45);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(62, 13);
			this->label11->TabIndex = 27;
			this->label11->Text = L"Merge ratio";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(435, 487);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(42, 23);
			this->button5->TabIndex = 28;
			this->button5->Text = L"Clear";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(978, 476);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(42, 23);
			this->button6->TabIndex = 29;
			this->button6->Text = L"Clear";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(655, 52);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(41, 13);
			this->label12->TabIndex = 30;
			this->label12->Text = L"label12";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(497, 46);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(33, 13);
			this->label13->TabIndex = 35;
			this->label13->Text = L"Noise";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(536, 46);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(40, 20);
			this->textBox4->TabIndex = 34;
			this->textBox4->Text = L"10";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(582, 48);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(18, 13);
			this->label14->TabIndex = 33;
			this->label14->Text = L"%";
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(503, 25);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(52, 17);
			this->checkBox2->TabIndex = 36;
			this->checkBox2->Text = L"Noise";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(978, 75);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(82, 17);
			this->checkBox3->TabIndex = 37;
			this->checkBox3->Text = L"Result class";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(902, 38);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(30, 20);
			this->textBox5->TabIndex = 38;
			this->textBox5->Text = L"10";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(861, 43);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(35, 13);
			this->label9->TabIndex = 39;
			this->label9->Text = L"n-fold";
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(232, 72);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(118, 17);
			this->checkBox4->TabIndex = 40;
			this->checkBox4->Text = L"Class column at 1st";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(485, 463);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(0, 13);
			this->label15->TabIndex = 41;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(537, 66);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(39, 13);
			this->label16->TabIndex = 42;
			this->label16->Text = L"#Runs";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1096, 563);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->richTextBox5);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->richTextBox4);
			this->Controls->Add(this->richTextBox3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
//own vars
	private: ArrayList ^trainfile;
	private: ArrayList ^AcumilateFile;
	private: ArrayList ^testfile;
	//		 Mat *TrainMat;
	//		 Mat *TestMat;
	//		 long col;
	//		 long row;
			Random ^rnd;
/////////////////////////
	String ^ GlobalfName;
	private: System::Void openTrainFileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			String ^ filename="";
			System::Windows::Forms::DialogResult dresult;
			dresult=ofdlg1->ShowDialog();
			 System::Windows::Forms::DialogResult ok =System::Windows::Forms::DialogResult::OK;
			if (dresult == ok){
				filename=ofdlg1->FileName;
				GlobalfName=filename;
//========
				//std::ifstream fleMembers(filename->ToCharArray());
				System::IO::FileInfo  ^fleMembers = gcnew FileInfo(filename);
				StreamReader ^swrMembers = fleMembers->OpenText();
				this->statusStrip1->Text=String::Concat("  Loading File: ,",filename, "For Training...");

				if(trainfile)
					trainfile->Clear();
				else
					trainfile=gcnew ArrayList();
				if(TrainMat){
					delete TrainMat; TrainMat=0;}
				if(TestMat)
					{delete TestMat; TestMat=0;}
				if(testfile)
					testfile->Clear();

	//			swrMembers->
				//int dd=fleMembers->Length-48;
	 			String ^line =swrMembers->ReadLine();
				//wchar_t spaceCh=' ';
				//cli::array<wchar_t,1>^ spaceCh;
				//spaceCh=' ';
				
				String^ delimStr;//= " ";
				long indexofcomma=line->IndexOf(",");
				if (indexofcomma > 0 && indexofcomma < line->Length-1)
					delimStr= ",";
				else
					delimStr= " ";


				array<Char>^ delimiter = delimStr->ToCharArray( );
				array<String^>^ WordsNumbers;
				WordsNumbers = line->Split(delimiter);
	/*			if (WordsNumbers[0]==" " || WordsNumbers[0]=="" ){
					col=WordsNumbers->Length-2;
					for (int k= 0;k<WordsNumbers->Length-1;k++)
						WordsNumbers[k]=WordsNumbers[k+1];
				}
				else */
				col=WordsNumbers->Length-1;

				long linctr=0;
				while(line){

				//	trainfile->Add(String::Concat(line,"\t"));
					trainfile->Add(line);
					//this->richTextBox1->AppendText(String::Concat(line,"\n"));
					line =swrMembers->ReadLine();
					++linctr;
					if (linctr/500== (float)linctr/500.0)
						this->label3->Text=linctr.ToString();
					Application::DoEvents();

				}
				this->label3->Text=linctr.ToString();
				//trainfile->Sort();
				swrMembers->Close();
				row=trainfile->Count;
				if (TrainMat){delete TrainMat; TrainMat=0;}
				TrainMat=new Mat(row,col);
				long j;
				this->progressBar1->Maximum=row;
				progressBar1->Value=0;
				/*for(j=0;j<col;j++){
						TrainMat->set(0,j,Convert::ToDouble(WordsNumbers[j]));
					}
				TrainMat->classint[0] = Convert::ToInt32(WordsNumbers[j]);*/
//============just delete
			/*	ArrayList ^trainfile2= gcnew ArrayList();
				for (long r=0;r<trainfile->Count;r++){
					String ^str1= safe_cast <String ^ > (trainfile[r])  ;
					String ^str2="";
					for (long i=0;i<str1->Length;i++){
						str2=String::Concat(str2,str1->Substring(str1->Length-1-i,1));
					}
					trainfile2->Add(str2);
				}
				trainfile2->Sort();
				trainfile->Clear();

				for (long r=0;r<trainfile->Count;r++){
					String ^str1= safe_cast <String ^ > (trainfile2[r])  ;
					String ^str2="";
					for (long i=0;i<str1->Length;i++){
						str2=String::Concat(str2,str1->Substring(str1->Length-1-i,1));
					}
					trainfile->Add(str2);
				}
				trainfile2->Clear();*/
//==========end delete				
				//strcpy(TrainMat->classes[0], WordsNumbers[j]);
				for (long i=0;i<trainfile->Count;i++){
					WordsNumbers->Clear;
					String ^temp= safe_cast <String ^> (trainfile[i])  ;
					WordsNumbers = temp->Split(delimiter);
					if (this->checkBox4->Checked)
						for( j=1;j<col+1;j++)
							TrainMat->set(i,j-1,Convert::ToDouble(WordsNumbers[j]));
					else
						for( j=0;j<col;j++)
							TrainMat->set(i,j,Convert::ToDouble(WordsNumbers[j]));
					if (this->checkBox4->Checked)
						TrainMat->classint[i] = Convert::ToInt32(Convert::ToDouble(WordsNumbers[0]));
					else
						TrainMat->classint[i] = Convert::ToInt32(Convert::ToDouble(WordsNumbers[j]));

					progressBar1->Value++;
					Application::DoEvents();

				}
				trainfile->Clear();
				
				this->statusStrip1->Text=String::Concat("File: ,",filename, "  Loaded ..");
				String ^temp;
				temp="number of vars:";
				temp=String::Concat(temp,(col).ToString()," ");
				temp=String::Concat(temp,"number of Examples : ",TrainMat->Row().ToString()/*(row).ToString()*/," ");
				TrainMat->setMaxes();
				float minv=9999999999999999999999999999999.0;
				float maxv=-9999999999999999999999999999999.0;
				for (int i=0;i<TrainMat->Col();i++){
					if (TrainMat->Min[i] < minv)
						minv=TrainMat->Min[i];
					if (TrainMat->Max[i] > maxv)
						maxv=TrainMat->Max[i];
				}
				String ^Rangestr=gcnew String("["+ minv.ToString()+","+maxv.ToString()+"]");
				this->richTextBox1->AppendText(Rangestr);
				temp=String::Concat(temp,"class at column:",(col+1).ToString(), " Range from: ", minv.ToString(), " To: ", maxv.ToString());
				this->statusStrip1->Text=temp;
				this->label3->Text=temp;
			}
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->richTextBox1->Clear();
			 }
private: System::Void trainFileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //normalize train
			 TrainMat->Normalize();
		 }
private: System::Void showTrainFileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //show trian file
			 long n=Convert::ToUInt32(this->textBox4->Text);
			 if (n==0)
				 n=TrainMat->Row();
				for (int i=0;i<n;i++){
					String ^temp="";

					for(int j=0;j<TrainMat->Col();j++){
						temp=String::Concat(temp,Convert::ToString(TrainMat->get(i,j)),"\t");
					}
					temp=String::Concat(temp,"\n");
					richTextBox1->AppendText(temp);
				}

		 }
private: System::Void showClassesFromTrainToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
//show classes
	for (int i=0;i<TrainMat->Row();i++){
	  richTextBox3->AppendText(String::Concat(TrainMat->classint[i].ToString(),"\n"));
				}
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->richTextBox2->Clear();

		 }
private: System::Void matToArrayToMatToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //test
			ArrayList ^arr=MatToArrayList(TrainMat);
			delete TrainMat; TrainMat=0;
			TrainMat=ArrayListToMat(arr);
			testfunction();

		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
//create test set from train set
			 Mat * AllDATA;
			 if (TestMat){
				 AllDATA = Add2Mats(TestMat,TrainMat);
				 delete TestMat; TestMat=0;
				 delete TrainMat; TrainMat=0;
			 } 
			 else
				 AllDATA=TrainMat;
			long n=AllDATA->Row();
			long * Rndindxes = new long[n];
			float ratio=Convert::ToDouble(this->textBox1->Text);
			for (long i=0;i<n;i++)
				Rndindxes[i]=i;
			for (long i=0;i<n;i++){
				long index=rnd->Next(0,n);
				//swap index by its location
				long temp=Rndindxes[index];
				Rndindxes[index]=Rndindxes[i];
				Rndindxes[i]=temp;
			}
			
			long stride= ratio*n;//size of test data
			
		//initilize array of test indexes
		long * testIndexes=new long[stride];
		for(long j=0; j<stride;j++)
			testIndexes[j]=Rndindxes[j];
		TrainTestMats ttm;
		ttm =MatToMats(AllDATA,testIndexes,stride);//split data to train and test 
		delete [] testIndexes;testIndexes=0;
		TrainMat=ttm.train;
		
		TestMat=ttm.test;
		this->richTextBox2->AppendText("\nData splited to "+ TestMat->Row().ToString() +" test rows and " +
			TrainMat->Row().ToString()+ " Training rows............\n");

	delete [] Rndindxes;Rndindxes=0;

//return train mat as it is 
	

	delete AllDATA; AllDATA=0;


		 }
private: System::Void showTestFileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //show test file
				for (int i=0;i<TestMat->Row();i++){
					String ^temp="";

					for(int j=0;j<TestMat->Col();j++){
						temp=String::Concat(temp,Convert::ToString(TestMat->get(i,j)),"\t");
					}
					temp=String::Concat(temp,"\n");
					richTextBox2->AppendText(temp);
				}

		 }
private: System::Void showTestClassesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
//show testclasses
	for (int i=0;i<TestMat->Row();i++){	
		richTextBox4->AppendText(String::Concat(TestMat->classint[i].ToString(),"\n"));
				}

		 }
private: System::Void kNNToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //knn pure
			// TestMat->UpdateNorms();
			 float sum=0;
			 long *classinttwo=new long[TestMat->Row()];
			 long *classinttoo=new long[TestMat->Row()];
			 long * FN=new long[TestMat->NumberOfClasses()];
			 long * FP=new long[TestMat->NumberOfClasses()];
			 long * TN=new long[TestMat->NumberOfClasses()];
			 float * precision=new float[TestMat->NumberOfClasses()];
			 float * Recall=new float[TestMat->NumberOfClasses()];
             ArrayList^n=gcnew ArrayList();
		    long** classmat = new long*[TestMat->NumberOfClasses()];
            for(long i = 0; i < TestMat->NumberOfClasses(); ++i)
            classmat[i] = new long[TestMat->NumberOfClasses()];
			 for (long i=0;i<TestMat->Row();i++)
				{
					if ( ! n->Contains(TestMat->classint[i]))
						n->Add(TestMat->classint[i]);
			    }
					
				int k=Convert::ToInt32(this->textBox2->Text);
				this->progressBar1->Maximum=TestMat->Row();this->progressBar1->Value=0;
				Stopwatch ^timer = gcnew Stopwatch();   
				timer->Start();
				for (long i=0;i<TestMat->Row();i++){
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					int cs=knn(TrainMat,testRow,k);
					if (this->checkBox3->Checked)
						this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					classinttwo[i]=cs;
					classinttoo[i]=TestMat->classint[i];
					delete []testRow; testRow=0;
					this->progressBar1->Value++;
					Application::DoEvents();
				}
				timer->Stop();
				this->richTextBox2->AppendText(String::Concat("\ntime Elapsed KNN:", timer->ElapsedMilliseconds.ToString(),"\n"));

				long index1=0;
				long index2=0;

				
				for (long i=0;i<TestMat->NumberOfClasses();i++)
					for (long j=0;j<TestMat->NumberOfClasses();j++)
						classmat[i][j]=0;

                //confusion matrix 
				for (long i=0;i<TestMat->Row();i++){ 
				   index1=n->IndexOf(classinttoo[i]);
                   index2=n->IndexOf(classinttwo[i]);
				   if(classinttoo[i]== classinttwo[i])
						classmat[index1][index1]+=1;
					else
						classmat[index1][index2]+=1;
				}
                   
                delete []classinttoo;
                delete []classinttwo;


				long sumTP = 0;
            	for (long i=0;i<TestMat->NumberOfClasses();i++)
				{
					FN[i]=0;
					FP[i]=0;
					TN[i]=0;
					precision[i]=0.0;
					Recall[i]=0.0;
				}





            for (long i=0;i<TestMat->NumberOfClasses();i++)
					for (long j=0;j<TestMat->NumberOfClasses();j++)
						if(j!=i)
                  FP[i]+=classmat[i][j];

			for (long i=0;i<TestMat->NumberOfClasses();i++)
					for (long j=0;j<TestMat->NumberOfClasses();j++)
						if(j!=i)
                  FN[i]+=classmat[j][i];

			 for (long i=0;i<TestMat->NumberOfClasses();i++)					
                 sumTP+=classmat[i][i];
             
			 for (long k=0;k<TestMat->NumberOfClasses();k++)
                  TN[k]=sumTP-classmat[k][k];

             for (long m=0;m<TestMat->NumberOfClasses();m++)
				if(	classmat[m][m]+ FP[m] == 0)
                    precision[m]=0.0;
				else
					precision[m]=classmat[m][m]/(float)(classmat[m][m]+FP[m]);

			 for (long v=0;v<TestMat->NumberOfClasses();v++)
				if(classmat[v][v]+FN[v] == 0)
                   Recall[v]=0.0;
				else
                   Recall[v]=classmat[v][v]/(float)(classmat[v][v]+FN[v]);
                
              float AvgPrecision = 0.0;
			  float SumPrecision = 0.0;
			  float SumRecall = 0.0;
              float AvgRecall = 0.0;
              for (long z=0;z<TestMat->NumberOfClasses();z++)
			  {
				  SumPrecision+=precision[z];
				  SumRecall+=Recall[z];
			  }


                delete []TN;
                delete []FN;
				delete []FP;
                delete [] Recall;
				delete [] precision;
				for(long i = 0; i < TestMat->NumberOfClasses(); ++i) {
                   delete [] classmat[i];
                }
                delete [] classmat;
           
            AvgRecall=SumRecall/(float)TestMat->NumberOfClasses();
            AvgPrecision=SumPrecision/(float)TestMat->NumberOfClasses();
			AvgRecall=Math::Round(AvgRecall,4.0);
			AvgPrecision=Math::Round(AvgPrecision,4.0);


			sum=sum/(float) TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat(" KNN Result:\t",sum.ToString(),"\tRecall :",AvgRecall.ToString(),"\tPrecision:",AvgPrecision.ToString());
			this->richTextBox2->AppendText("k= " + this->textBox2->Text + label8->Text);
		 }
private: System::Void openTestFileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			String ^ filename="";
			System::Windows::Forms::DialogResult dresult;
			dresult=ofdlg1->ShowDialog();
			if (dresult ==System::Windows::Forms::DialogResult::OK){
				filename=ofdlg1->FileName;
//========
				System::IO::FileInfo  ^fleMembers = gcnew FileInfo(filename);
				StreamReader ^swrMembers = fleMembers->OpenText();
				this->statusStrip1->Text=String::Concat("  Loading File: ,",filename, "For Training...");
				if(testfile)
					testfile->Clear();
				else
					testfile=gcnew ArrayList();
				if(TestMat)
				{delete TestMat; TestMat=0;}
	 			String ^line =swrMembers->ReadLine();
				
  			String^ delimStr;//= " ";
			long indexofcomma=line->IndexOf(",");
			if (indexofcomma > 0 && indexofcomma < line->Length-1)
				delimStr= ",";
			else
				delimStr= " ";

				array<Char>^ delimiter = delimStr->ToCharArray( );
				array<String^>^ WordsNumbers;
				WordsNumbers = line->Split(delimiter);
				col=WordsNumbers->Length-1;
				
				while(line){
					testfile->Add(line);
					line =swrMembers->ReadLine();
				}

				swrMembers->Close();
				row=testfile->Count;
				if (TestMat){delete TestMat; TestMat=0;}
				TestMat=new Mat(row,col);
				long j;
				progressBar1->Maximum=row;
				progressBar1->Value=0;
				for (long i=0;i<testfile->Count;i++){
					WordsNumbers->Clear;
					String ^temp= safe_cast <String ^> (testfile[i])  ;
					WordsNumbers = temp->Split(delimiter);
					if (this->checkBox4->Checked)
						for( j=1;j<col+1;j++)
							TestMat->set(i,j-1,Convert::ToDouble(WordsNumbers[j]));
					else
						for( j=0;j<col;j++)
							TestMat->set(i,j,Convert::ToDouble(WordsNumbers[j]));
					if (this->checkBox4->Checked)
						TestMat->classint[i] = Convert::ToInt32(Convert::ToDouble(WordsNumbers[0]));
					else
						TestMat->classint[i] = Convert::ToInt32(Convert::ToDouble(WordsNumbers[j]));

					progressBar1->Value++;
					Application::DoEvents();

				}
				testfile->Clear();
				
				this->statusStrip1->Text=String::Concat("Test File: ,",filename, "  Loaded ..");
				String ^temp;
				temp="number of vars:";
				temp=String::Concat(temp,(col).ToString()," ");
				temp=String::Concat(temp,"number of examples:",(row).ToString()," ");
				temp=String::Concat(temp,"class at column:",(col+1).ToString());
				this->statusStrip1->Text=temp;
				this->label15->Text=temp;
			}

		 }
private: System::Void minAverageDistancesOfEachClassToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //min average distances between all poins of each class and test point
			 float sum=0;
				for (int i=0;i<TestMat->Row();i++){
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					int cs=AverageDistances(TrainMat,testRow);
					richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("Result: ",sum.ToString());
			this->richTextBox2->AppendText(label8->Text);

		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 rnd=gcnew Random(4443);
			 DistanceType=0;
		 }
private: System::Void trainCentroidsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //train centroids : find th averge vector for each class
			 TrainAverageClasses(TrainMat);

		 }
private: System::Void showTrainOutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //show trian output
				for (int i=0;i<TrainOut->Row();i++){
					String ^temp="";

					for(int j=0;j<TrainOut->Col();j++){
						temp=String::Concat(temp,Convert::ToString(TrainOut->get(i,j)),"\t");
					}
					temp=String::Concat(temp,TrainOut->classint[i].ToString(),"\n");
					richTextBox2->AppendText(temp);
				}

		 }
private: System::Void testCentroidsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		//	 test centroid
			 float sum=0;
				for (int i=0;i<TestMat->Row();i++){
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					int cs=TestAverageClasses(testRow);
					richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("Result using centroids: ",sum.ToString());

		 }
private: System::Void kNNSumDistamcesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 //knn knnSumDist
			 float sum=0;
				int k=Convert::ToInt32(this->textBox2->Text);
				for (int i=0;i<TestMat->Row();i++){
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					int cs=knnSumDist(TrainMat,testRow,k);
					this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("Result: ",sum.ToString());

		 }
private: System::Void trainCentroidUsingMediansToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //train centroids : find the median vector for each class
			 TrainMedianClasses(TrainMat);

		 }
private: System::Void testCentroidsUsingMediansToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		//	 test centroid using medians
			 float sum=0;
				for (int i=0;i<TestMat->Row();i++){
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					int cs=TestMedianClasses(testRow);
					richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("Result using median centroids: ",sum.ToString());

		 }
private: System::Void trainQuartilesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //training using quartiles as lower and upper bound 
			 TrainQuartilesClasses(TrainMat);

		 }
private: System::Void testQuartilesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		//	 test   using quartiles as lower and upper bound
			 float sum=0;
				for (int i=0;i<TestMat->Row();i++){
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					int cs=TestQuartilesClasses(testRow);
					richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("Result using quartiles: ",sum.ToString());

		 }
private: System::Void showTrain2OutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //show trian2 output
			 for (int cls=0;cls<ClassCount;cls++){
				 richTextBox2->AppendText(String::Concat("\nClass:",cls.ToString(),"\n"));
				for (int i=0;i<TrainOut2[cls]->Row();i++){
					String ^temp="";

					for(int j=0;j<TrainOut2[cls]->Col();j++){
						temp=String::Concat(temp,Convert::ToString(TrainOut2[cls]->get(i,j)),"\t");
					}
					temp=String::Concat(temp,"\n");
					richTextBox2->AppendText(temp);
				}
				}

		 }
private: System::Void kNNChangeKFrom1ToSqrtTrnsetToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //knn changing k from 1 to 
			 ClassCount=TrainMat->NumberOfClasses();
	float *distance = new float [ClassCount];
	//initilize dist

			
				float sum=0;
				for (int i=0;i<TestMat->Row();i++){
					for (int cls=0;cls<ClassCount;cls++)
						distance[cls]=0.0;
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					for (int k=1;k< Math::Sqrt(TrainMat->Row());k++){			
						int cs=knn(TrainMat,testRow,k);
						distance[cs]++;
					}
					int cs=argmax(distance,ClassCount);
					this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("Result knn K=1-sqrt(n): ",sum.ToString());
		 delete [] distance; distance=0;
		 }
private: System::Void kNNToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
		//	 KNN min sum of distances weighted using inverse fib 
			 float sum=0;
				int k=Convert::ToInt32(this->textBox2->Text);
				for (int i=0;i<TestMat->Row();i++){
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					int cs=knnSumDistFib(TrainMat,testRow,k);
				//	for (int j=0;j<TrainMat->Row();j++)
				//	this->richTextBox2->AppendText(String::Concat(twovaluesarr[j].v1.ToString(),"\t",twovaluesarr[j].v2.ToString(),"\n"));
				//return ;
				
					//end

					this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("Result:KNN min sum dist fib ",sum.ToString());

		 }
private: System::Void trainBoundariesMedianRowsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
////train using the row of the median of a givin class of a given feature 
			 TrainRowsMediansClasses(TrainMat);
			 

		 }
private: System::Void testBoundariesMedianRowsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
//----------test  using rows of medians of classe  as boundaries
			 float sum=0;
				for (int i=0;i<TestMat->Row();i++){
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					int cs=TestRowsMediansClasses(testRow);
					richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/(float) TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("Result using med boundaries: ",sum.ToString());

		 }
private: System::Void trainBndryAvgQuartileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
//training average rows of quartiles  of classe  as boundaries
			 TrainRowsAvgQuartilesClasses(TrainMat);

		 }
private: System::Void testBndryAvgQuartileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

//----test using average rows of quartiles  of classe  as boundaries
			 float sum=0;
				for (int i=0;i<TestMat->Row();i++){
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					int cs=TestRowsAvgQuartilesClasses(testRow);
					richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/(float) TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("Result using avg qrtile boundaries: ",sum.ToString());

		 }
private: System::Void testBndryAvgQuarEDToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
//----test using average rows of quartiles  of classe  as boundaries using ED distance
			 float sum=0;
				for (int i=0;i<TestMat->Row();i++){
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					int cs=TestRowsAvgQuartilesClassesED(testRow);
					richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/(float) TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("Result using avg qrtile boundaries ED: ",sum.ToString());

		 }
private: System::Void nNMajorityToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
//knn: NN Majority take the minimum distances and go down until you get all the classes : 
//now majority role, so no need for k
			 float sum=0;
				for (int i=0;i<TestMat->Row();i++){
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					int cs=NNMajority(TrainMat,testRow);
					this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("NN Majority: ",sum.ToString());

		 }
private: System::Void nNMsxDisMinorityToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
//knn: NN Minority take the max distances and go down until you get all the classes : 
//now Minority rule, so no need for k
			 float sum=0;
				for (int i=0;i<TestMat->Row();i++){
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					int cs=NNMinority(TrainMat,testRow);
					this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("NN Minority: ",sum.ToString());

		 }
private: System::Void nNToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
//knn: take the minimum  and maximum distances for each class average them 
//and take the class of the min verage NNMinMaxAvrg
			 float sum=0;
				for (int i=0;i<TestMat->Row();i++){
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					int cs=NNMinMaxAvrg(TrainMat,testRow);
					this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("NN MinMaxAvrg: ",sum.ToString());

		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		Mat *temp=TrainMat;
		TrainMat = TestMat;
		TestMat =temp;

		 }
private: System::Void trainingAveragesOfSubClassesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
/*
training averages of sub classes
1- take all the average of each class
2- classify all points based on the averages of each class
3- any point does not classified well remove it from the class bag and put it in the unknown class i bag
4- take the new average again and classify the rest of the points until no more fvs are moving to unknown bags
5- the resulting averages are to be used in the model later
now go to the unknown bags of each class until now more fv in all unknown bags 
*/
			 TrainingAveragesOfSubClasses(TrainMat);

		 }
private: System::Void testAveragesOfSubClassesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			// TrainQuartilesClasses(TrainOut);
			//	TrainRowsMediansClasses(TrainOut);
			// TrainRowsAvgQuartilesClasses(TrainOut);

			 //test averages of sub classes using knn
			 float sum=0;
				int k=Convert::ToInt32(this->textBox2->Text);
				for (int i=0;i<TestMat->Row();i++){
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					//int cs=knn(TrainOut,testRow,k);
					//int cs=NNMinority(TrainOut,testRow,k); 
					//int cs=NNMajority(TrainOut,testRow);
				//	int cs=AverageDistances(TrainOut,testRow); TestAveragesOfSubClasses
				//	int cs=NNMinMaxAvrg(TrainOut,testRow); 
				//	int cs=knnSumDist(TrainOut,testRow,k);
				//	int cs=knnSumDistFib(TrainOut,testRow,k);
				//	int cs=TestQuartilesClasses(testRow);
				//	int cs=TestRowsMediansClasses(testRow);
				//	int cs=TestRowsAvgQuartilesClasses(testRow);
					int cs=TestAveragesOfSubClasses2(testRow); 
					this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("TestAveragesOfSubClasses: ",sum.ToString());

		 }
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 DistanceType= comboBox1->SelectedIndex;

			this->richTextBox1->AppendText(DistanceType.ToString());
			//MessageBox::Show(Convert::ToString(comboBox1->Items[5]));
		 }
private: System::Void showTrain3OutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //show train  3
			 for (int cls=0;cls<NumberofRuns;cls++){
				 richTextBox2->AppendText(String::Concat("\nRun: ",cls.ToString(),"\n"));
				for (int i=0;i<TrainOut3[cls]->Row();i++){
					String ^temp="";

					for(int j=0;j<TrainOut3[cls]->Col();j++){
						temp=String::Concat(temp,Convert::ToString(TrainOut3[cls]->get(i,j)),"\t");
					}
					temp=String::Concat(temp,TrainOut3[cls]->classint[i].ToString(),"\n");
					richTextBox2->AppendText(temp);
				}
				}

		 }
private: System::Void testAverageOfSubClsVotesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //TestAveragesOfSubClassesVote

			 float sum=0;
				int k=Convert::ToInt32(this->textBox2->Text);
				for (int i=0;i<TestMat->Row();i++){
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					int cs=TestAveragesOfSubClassesVote(testRow); 
					this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("TestAveragesOfSubClassesVote: ",sum.ToString());

		 }
private: System::Void genaticAlgorithmsToChooseBestExamToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

/*
genatic algorithm to find the best FV to represent each class k iteration
take randomly a number of fv for each class, classify trainnig data using these feature vectors
fitness function is the maximum accuricey, keep good fvs, reomve ones drop accuracy
cross-over: rplace with other fv of the same class
mutation, increament and decremnet by a smal fraction on randomly chosen feature.
*/
			int k=Convert::ToInt32(this->textBox2->Text);//number of iterations 

			float GaAccuracy= GATrainBestExamples(TrainMat,k);
			label8->Text=String::Concat("Ga training Accuracy: ",GaAccuracy.ToString());

		 }
private: System::Void testGAToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//genatic algorithm test
			//update weights
			 for (int c=0;c<TestMat->Col();c++){
				 TrainOut->weights[c]=TrainMat->weights[c];
			 }

			 float sum=0;
				int k=Convert::ToInt32(this->textBox2->Text);
				for (int i=0;i<TestMat->Row();i++){
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					int cs=knn(TrainOut,testRow,k);
					//int cs=NNMinority(TrainOut,testRow,k); 
					//int cs=NNMajority(TrainOut,testRow);
				//	int cs=AverageDistances(TrainOut,testRow); TestAveragesOfSubClasses
				//	int cs=NNMinMaxAvrg(TrainOut,testRow); 
				//	int cs=knnSumDist(TrainOut,testRow,k);
				//	int cs=knnSumDistFib(TrainOut,testRow,k);
				//	int cs=TestQuartilesClasses(testRow);
				//	int cs=TestRowsMediansClasses(testRow);
				//	int cs=TestRowsAvgQuartilesClasses(testRow);
					this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("Test GA: ",sum.ToString());

		 }
private: System::Void testGANNMajorityToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//genatic algorithm test
			//update weights
			 for (int c=0;c<TestMat->Col();c++){
				 TrainOut->weights[c]=TrainMat->weights[c];
			 }

			 float sum=0;
				int k=Convert::ToInt32(this->textBox2->Text);
				for (int i=0;i<TestMat->Row();i++){
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					//int cs=knn(TrainOut,testRow,k);
					//int cs=NNMinority(TrainOut,testRow,k); 
					int cs=NNMajority(TrainOut,testRow);
				//	int cs=AverageDistances(TrainOut,testRow); TestAveragesOfSubClasses
				//	int cs=NNMinMaxAvrg(TrainOut,testRow); 
				//	int cs=knnSumDist(TrainOut,testRow,k);
				//	int cs=knnSumDistFib(TrainOut,testRow,k);
				//	int cs=TestQuartilesClasses(testRow);
				//	int cs=TestRowsMediansClasses(testRow);
				//	int cs=TestRowsAvgQuartilesClasses(testRow);
					this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("Test GA: ",sum.ToString());

		 }
private: System::Void trainWeightUsingNNToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
//train weights

			 //knnsub feature
	//		 String ^ str=str="";
			 String ^ str="";
			 float sum, total=0.0;
			 int row=TrainMat->Row(), col=TrainMat->Col();
			 float *testRow=new float[col];
			for (int c=0;c<col;c++){
				sum=0.0;
				for (int i=0;i<row;i++){
					
					TrainMat->getRow(testRow,i);
					int cs=knnSubFeature(TrainMat,testRow,1,c,i);
					if (TrainMat->classint[i]==cs)
						sum++;
				}
				sum= sum/(float) row;
				total=total+sum;
				TrainMat->weights[c]= 1.0- sum;//error ratio used as weight
			}
			for (int c=0;c<col;c++){
			//	TrainMat->weights[c] =1.0 - (TrainMat->weights[c]/total);
				str=String::Concat(str,TrainMat->weights[c].ToString(),"\t");
			}
delete []testRow; testRow=0;


			this->richTextBox2->AppendText(String::Concat("weights: \n",str));

		 }
private: System::Void trainBestFVsNNAccuracyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
/*
another method: take for each fv for each class , use this feature vector as a centroid, use the average as centroid
for other classes, test trainig set based on these m fvs and record the accuricy, consider the feature vectors of 
the maximu classifying accuricy to represent their clsses in the training model
*/
			int k=Convert::ToInt32(this->textBox2->Text);
			NNTrainBestExamples(TrainMat, k);
			label8->Text=String::Concat("NN best exmpls training done: ","\t");

		 }
private: System::Void testTrnBestNNMajorityToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//NNTrainBestExamples test
			 float sum=0;
			 //update weights on train out
			 for (int c=0;c<TestMat->Col();c++){
				 TrainOut->weights[c]=TrainMat->weights[c];
			 }
				int k=Convert::ToInt32(this->textBox2->Text);
				for (int i=0;i<TestMat->Row();i++){
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					//int cs=knn(TrainOut,testRow,k);
					//int cs=NNMinority(TrainOut,testRow,k); 
					int cs=NNMajority(TrainOut,testRow);
				//	int cs=AverageDistances(TrainOut,testRow); TestAveragesOfSubClasses
				//	int cs=NNMinMaxAvrg(TrainOut,testRow); 
				//	int cs=knnSumDist(TrainOut,testRow,k);
				//	int cs=knnSumDistFib(TrainOut,testRow,k);
				//	int cs=TestQuartilesClasses(testRow);
				//	int cs=TestRowsMediansClasses(testRow);
				//	int cs=TestRowsAvgQuartilesClasses(testRow);
					this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("Test NN best example: ",sum.ToString());

		 }
private: System::Void trainUsingMinimumDistanceToGetBoundaryPointsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //train using minimum distance to get boundary points
			 int k=Convert::ToInt32(this->textBox2->Text);
			 this->richTextBox1->AppendText(MinDistanceBoundaryPoints(TrainMat, k));


		 }
private: System::Void testMDBPToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			//test using minimum distance to get boundary points
			 	float sum=0.0;
				int k=Convert::ToInt32(this->textBox2->Text);
				for (int i=0;i<TestMat->Row();i++){
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					//int cs=knn(TrainOut,testRow,k);
					//int cs=NNMinority(TrainOut,testRow,k); 
					int cs=NNMajority(TrainOut,testRow);
				//	int cs=AverageDistances(TrainOut,testRow); TestAveragesOfSubClasses
				//	int cs=NNMinMaxAvrg(TrainOut,testRow); 
				//	int cs=knnSumDist(TrainOut,testRow,k);
				//	int cs=knnSumDistFib(TrainOut,testRow,k);
				//	int cs=TestQuartilesClasses(testRow);
				//	int cs=TestRowsMediansClasses(testRow);
				//	int cs=TestRowsAvgQuartilesClasses(testRow);
					this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("Test MDBP: ",sum.ToString());

		 }
private: System::Void trainGAOfNonZeroMDBPToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //train the resulting nono zero votes trainout of MDBP using GA to get the best of the best
			 if (TrainOut){
				int k=Convert::ToInt32(this->textBox2->Text);//number of iterations 
				if (k<100)
					k=100;
				float GaAccuracy= GATrainBestExamplesofMDBP(TrainMat,k);
				label8->Text=String::Concat("Ga MDBP train Accuracy: ",GaAccuracy.ToString());
			 }
			 else 
				 MessageBox::Show("no training data in Trainout..!");

		 }
private: System::Void testGAMDBPToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//genatic algorithm on MDBP
			 if (TrainOut1){
			 float sum=0;
				int k=Convert::ToInt32(this->textBox2->Text);
				for (int i=0;i<TestMat->Row();i++){
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					int cs=knn(TrainOut1,testRow,k);
					//int cs=NNMinority(TrainOut,testRow,k); 
					//int cs=NNMajority(TrainOut,testRow);
				//	int cs=AverageDistances(TrainOut,testRow); TestAveragesOfSubClasses
				//	int cs=NNMinMaxAvrg(TrainOut,testRow); 
				//	int cs=knnSumDist(TrainOut,testRow,k);
				//	int cs=knnSumDistFib(TrainOut,testRow,k);
				//	int cs=TestQuartilesClasses(testRow);
				//	int cs=TestRowsMediansClasses(testRow);
				//	int cs=TestRowsAvgQuartilesClasses(testRow);
					this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("Test GA-MDBP: ",sum.ToString());
			 }
			 else
				MessageBox::Show("no training data in Trainout1..!");
		 }
private: System::Void showTrainOut1ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //show trian output1
			 if (TrainOut1){
				for (int i=0;i<TrainOut1->Row();i++){
					String ^temp="";

					for(int j=0;j<TrainOut->Col();j++){
						temp=String::Concat(temp,Convert::ToString(TrainOut->get(i,j)),"\t");
					}
					temp=String::Concat(temp,TrainOut->classint[i].ToString(),"\n");
					richTextBox2->AppendText(temp);
				}
				}
			 else
				MessageBox::Show("no training data in Trainout1..!");


		 }
private: System::Void kNNChangeKFrom1ToSqrtNOddKsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 //knn changing k from 1 to n using odd ks 
			 ClassCount=TrainMat->NumberOfClasses();
	float *distance = new float [ClassCount];
	//initilize dist

			
				float sum=0;
				for (int i=0;i<TestMat->Row();i++){
					for (int cls=0;cls<ClassCount;cls++)
						distance[cls]=0.0;
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					for (int k=1;k< Math::Sqrt(TrainMat->Row());k+=2){			
						int cs=knn(TrainMat,testRow,k);
						distance[cs]++;//=1.0/Math::Log(1+k,2.0);
					}
					int cs=argmax(distance,ClassCount);
					this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("Result knn K=1-sqrt(n)odd ks: ",sum.ToString());
		 delete [] distance; distance=0;


		 }
private: System::Void kNNChangeKFrom1ToSqrtNOddKsWeightsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 //knn changing k from 1 to n using odd ks with weights the biggest to the nn
/*	ClassCount=TrainMat->NumberOfClasses();
	float *distance = new float [ClassCount];*/
	//initilize dist	
				float sum=0;
				for (int i=0;i<TestMat->Row();i++){
				//	for (int cls=0;cls<ClassCount;cls++)
					//	distance[cls]=0.0;
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
				/*	for (int k=1;k<= Math::Sqrt(TrainMat->Row());k+=2){			
						int cs=knn(TrainMat,testRow,k);
						distance[cs]+=1.0/Math::Log(1+k,2.0);
						//do inverted inex +=1/k  
					int cs=argmax(distance,ClassCount);}*/
					int k=Math::Sqrt(TrainMat->Row());
					int cs=Ensimbleknn(TrainMat,testRow,k);
					this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("Result knn K=1-sqrt(n)odd ks with weights: ",sum.ToString());
			this->richTextBox2->AppendText(label8->Text);
		// delete [] distance; distance=0;

		 }
private: System::Void kNNChangeKFrom1ToSqrtNKsWeightsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //knn changing k from 1 to n using odd ks with weights the biggest to the nn
			 ClassCount=TrainMat->NumberOfClasses();
	float *distance = new float [ClassCount];
	//initilize dist

			
				float sum=0;
				for (int i=0;i<TestMat->Row();i++){
					for (int cls=0;cls<ClassCount;cls++)
						distance[cls]=0.0;
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					for (int k=1;k< Math::Sqrt(TrainMat->Row());k++){			
						int cs=knn(TrainMat,testRow,k);
						distance[cs]+=1.0/Math::Log(1+k,2.0);
					}
					int cs=argmax(distance,ClassCount);
					this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("Result knn K=1-sqrt(n)all ks with weights: ",sum.ToString());
		 delete [] distance; distance=0;

		 }
private: System::Void testKnnWithDifferenToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //knn multi distances , multi data sets
		//output file to tesult.txt
		
//open files
	String ^ filename="";
	System::Windows::Forms::DialogResult dresult;
	dresult=ofdlg1->ShowDialog();
	if (dresult ==System::Windows::Forms::DialogResult::OK){
		StreamWriter^ outfile = gcnew StreamWriter("tesult.txt");
		this->progressBar1->Maximum=63*10* ofdlg1->FileNames->Length;
		progressBar1->Value=0;
		//String 
		int f=0;
		for (int f=0;f < ofdlg1->FileNames->Length;f++){
		//for each (filename in ofdlg1->FileNames){
			Application::DoEvents();
				filename=ofdlg1->FileNames[f];

//========
				System::IO::FileInfo  ^fleMembers = gcnew FileInfo(filename);
				StreamReader ^swrMembers = fleMembers->OpenText();
				this->statusStrip1->Text=String::Concat("  Loading File: ,",filename, "For Training...");
				if(trainfile)
					trainfile->Clear();
				else
					trainfile=gcnew ArrayList();
				if(TrainMat){
					delete TrainMat; TrainMat=0;}
				if(TestMat)
					{delete TestMat; TestMat=0;}
				if(testfile)
					testfile->Clear();

	 			String ^line =swrMembers->ReadLine();
				
				String^ delimStr= " ";
				array<Char>^ delimiter = delimStr->ToCharArray( );
				array<String^>^ WordsNumbers;
				WordsNumbers = line->Split(delimiter);
				col=WordsNumbers->Length-1;
				
				while(line){

					trainfile->Add(line);
					line =swrMembers->ReadLine();
				}
				swrMembers->Close();
				
				row=trainfile->Count;
				TrainMat=new Mat(row,col);
				int j;
				for(j=0;j<col;j++){
						TrainMat->set(0,j,Convert::ToDouble(WordsNumbers[j]));
					}
				TrainMat->classint[0] = Convert::ToInt32(WordsNumbers[j]);
				for (int i=1;i<trainfile->Count;i++){
					WordsNumbers->Clear;
					String ^temp= safe_cast <String ^> (trainfile[i])  ;
					WordsNumbers = temp->Split(delimiter);
					for( j=0;j<col;j++){
						TrainMat->set(i,j,Convert::ToDouble(WordsNumbers[j]));
					}
					TrainMat->classint[i] = Convert::ToInt32(WordsNumbers[j]);
				}
				trainfile->Clear();
				
				String ^temp;
				temp= filename->Substring(1+ filename->LastIndexOf("\\"));
				temp=String::Concat(temp, "  Loaded ..:","\n");
				temp=String::Concat(temp,"number of vars: ",(col).ToString(),"\n");
				temp=String::Concat(temp,"number of examples: ",(row).ToString(),"\n");
				temp=String::Concat(temp,"class at column: ",(col+1).ToString(),"\n");
				this->richTextBox2->AppendText(temp);
				outfile->Write(temp);
//end open
//creat sample test file


//end  creat sample test file
//remove random examples from train and insert em into test set
			 if(!TrainMat){
				MessageBox::Show("no train data ..");

				 goto exit_sub;
			 }

float r = 0.0;
			 //Nois data
if (this->checkBox2->Checked)
{	 r = Convert::ToInt32(textBox4->Text)/100.0; 
			 TrainMat->Noise(r);
}

	for (int TestNumer=0; TestNumer <10;TestNumer++){ //repeat the test on different sample
		Application::DoEvents();
		ArrayList ^train=MatToArrayList(TrainMat);
		int row;
		//int i;
		ArrayList ^test;//=gcnew ArrayList ();
		if(TestMat){
				test=MatToArrayList(TestMat);
				 delete TestMat; TestMat=0;
				 int testcount=test->Count;
				 for (int i=0;i<testcount;i++){
					train->Add(test[0]);
					test->RemoveAt(0);
				 }
			 }
			 else
				test=gcnew ArrayList ();



		row=train->Count;
		bool *visited=new bool[row];
		for(int i=0;i<row;i++){
			visited[i]=false;
		}
		//Random ^rnd=gcnew Random(4443);
		float ratio=Convert::ToDouble(this->textBox1->Text);
		int testSize= ratio*row;

		for (int i=0;i<testSize;i++){
nextrnd:
			int rownum=rnd->Next(0,train->Count-1);
			if(visited[rownum])
				goto nextrnd;
			visited[rownum]=true;
			test->Add(train[rownum]);
			train->RemoveAt(rownum);
		}
		delete TrainMat; TrainMat=0;
		delete TestMat; TestMat=0;
		TrainMat=ArrayListToMat(train);
		TestMat=ArrayListToMat(test);
		train->Clear();
		test->Clear();
		
		delete []visited; visited=0;
exit_sub:
		this->richTextBox2->AppendText("\nTest Sample:" + (TestNumer+1).ToString() + "\n" );
		outfile->WriteLine("\nTest Sample:" + (TestNumer+1).ToString() + "\n");
		this->richTextBox2->AppendText("number of test Examples:" + TestMat->Row().ToString() + "\n" );
		outfile->WriteLine("number of test Examples:" + TestMat->Row().ToString() + "\n");
       

		for (int dist=0;dist<62;dist++){
			//do test for each dist 
			float sum=0.0;
			 int *classinttwo=new int[TestMat->Row()];
			 int *classinttoo=new int[TestMat->Row()];
			 int * FN=new int[TestMat->NumberOfClasses()];
			 int * FP=new int[TestMat->NumberOfClasses()];
			 int * TN=new int[TestMat->NumberOfClasses()];
			 float * precision=new float[TestMat->NumberOfClasses()];
			 float * Recall=new float[TestMat->NumberOfClasses()];
             ArrayList^n=gcnew ArrayList();
		    int** classmat = new int*[TestMat->NumberOfClasses()];
            for(int i = 0; i < TestMat->NumberOfClasses(); ++i)
            classmat[i] = new int[TestMat->NumberOfClasses()];
			 for (int i=0;i<TestMat->Row();i++)
				{
					if ( ! n->Contains(TestMat->classint[i]))
						n->Add(TestMat->classint[i]);
			    }			
			int k=Convert::ToInt32(this->textBox2->Text);
			DistanceType=dist;
			for (int ii=0;ii<TestMat->Row();ii++){
				float *testRow=new float[TestMat->Col()];
				TestMat->getRow(testRow,ii);
				int cs=knn(TrainMat,testRow,k);
				if (TestMat->classint[ii]==cs)
					sum++;
			    	classinttwo[ii]=cs;
					classinttoo[ii]=TestMat->classint[ii];
				delete []testRow; testRow=0;
			}
			int index1=0;
				int index2=0;

				
				for (int i=0;i<TestMat->NumberOfClasses();i++)
					for (int j=0;j<TestMat->NumberOfClasses();j++)
                   classmat[i][j]=0;

                //confusion matrix 
				for (int i=0;i<TestMat->Row();i++)
				{    index1=n->IndexOf(classinttoo[i]);
                   index2=n->IndexOf(classinttwo[i]);  
					if(classinttoo[i]== classinttwo[i])
			      classmat[index1][index1]+=1;
					else
                  classmat[index1][index2]+=1;

				}
                   
                delete []classinttoo;
                delete []classinttwo;


				int sumTP = 0;
            	for (int i=0;i<TestMat->NumberOfClasses();i++)
				{
					FN[i]=0;
					FP[i]=0;
					TN[i]=0;
					precision[i]=0.0;
					Recall[i]=0.0;
				}





            for (int i=0;i<TestMat->NumberOfClasses();i++)
					for (int j=0;j<TestMat->NumberOfClasses();j++)
						if(j!=i)
                  FP[i]+=classmat[i][j];

			for (int i=0;i<TestMat->NumberOfClasses();i++)
					for (int j=0;j<TestMat->NumberOfClasses();j++)
						if(j!=i)
                  FN[i]+=classmat[j][i];

			 for (int i=0;i<TestMat->NumberOfClasses();i++)					
                 sumTP+=classmat[i][i];
             
			 for (int k=0;k<TestMat->NumberOfClasses();k++)
						
                  TN[k]=sumTP-classmat[k][k];

             for (int m=0;m<TestMat->NumberOfClasses();m++)
				if(	classmat[m][m]+ FP[m] == 0)
                    precision[m]=0.0;
				else
					precision[m]=classmat[m][m]/(float)(classmat[m][m]+FP[m]);

			 for (int v=0;v<TestMat->NumberOfClasses();v++)
				if(classmat[v][v]+FN[v] == 0)
                   Recall[v]=0.0;
				else
                   Recall[v]=classmat[v][v]/(float)(classmat[v][v]+FN[v]);
                
              float AvgPrecision = 0.0;
			  float SumPrecision = 0.0;
			  float SumRecall = 0.0;
              float AvgRecall = 0.0;
              for (int z=0;z<TestMat->NumberOfClasses();z++)
			  {
				  SumPrecision+=precision[z];
				  SumRecall+=Recall[z];
			  }


                delete []TN;
                delete []FN;
				delete []FP;
                delete [] Recall;
				delete [] precision;
				for(int i = 0; i < TestMat->NumberOfClasses(); ++i) {
                   delete [] classmat[i];
                }
                delete [] classmat;
           
            AvgRecall=SumRecall/(float)TestMat->NumberOfClasses();
            AvgPrecision=SumPrecision/(float)TestMat->NumberOfClasses();
			AvgRecall=Math::Round(AvgRecall,4.0);
			AvgPrecision=Math::Round(AvgPrecision,4.0);

			sum=sum/(float) TestMat->Row();
			sum=Math::Round(sum,4.0);
			String ^temp=String::Concat(Convert::ToString(comboBox1->Items[DistanceType])," KNN Result:",sum.ToString(),"  Recall :",AvgRecall.ToString(),"  Precision:",AvgPrecision.ToString(),"\n");
			this->richTextBox2->AppendText(temp);
			outfile->Write(temp);
		progressBar1->Value++;
		}//for each distance 
	/*	delete TrainMat; TrainMat=0;
		delete TestMat; TestMat=0;
		train->Clear();
		test->Clear();*/

			 }//end for each test number
			this->richTextBox2->AppendText("\n");
			outfile->Write("\n");

}//end for each file
				outfile->Close();

			} //end if for open fil dialog result
	
		 }//end multi test knn 
private: System::Void eDNormBinsearchKNNToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //ED Norm binary search
	int row=TrainMat->Row(),  col=TrainMat->Col();
	twovalues *twovaluesarr; 
	twovaluesarr = new twovalues [row];
	//clac norm of row in data 
	int base;//number of cats
	base =Convert::ToInt16(this->textBox2->Text);
	for (int r=0;r<row;r++){
		float f1=0.0;
		for (int c=0;c<col;c++){
		//	f1+= TrainMat->get(r,c) * TrainMat->get(r,c);
		//	f1+= Math::Pow(2.0,c)*TrainMat->get(r,c);//karp-rabin signiture 2^c* vi
			f1+= Math::Pow(base,c)*TrainMat->get(r,c);
		}
		//f1= Math::Sqrt(f1);
		twovaluesarr[r].v1=f1;
		twovaluesarr[r].v2=r;
	}
	//sor records acording to their norms 	
	qs(twovaluesarr,row);
	twovalues range;
/*	float value= Convert::ToDouble(this->textBox1->Text);
	range = BinarySearch2values(twovaluesarr, row, value);

	this->richTextBox2->AppendText(String::Concat(range.v1.ToString()," - ", range.v2.ToString(), "\n"));
	this->richTextBox2->AppendText(String::Concat(twovaluesarr[(int)range.v1].v1.ToString()," - ", twovaluesarr[(int)range.v2].v1.ToString(), "\n"));
	this->richTextBox2->AppendText(String::Concat(twovaluesarr[(int)range.v1].v2.ToString()," - ", twovaluesarr[(int)range.v2].v2.ToString(), "\n"));
	int k=Convert::ToInt32(this->textBox2->Text);
	range.v1=range.v1-k;
	range.v2=range.v2+k;
	if (range.v1<0){
		range.v2=range.v2+Math::Abs(range.v1);
		range.v1=0;
	}
	if (range.v2>=row){
		range.v1=range.v1-(range.v2-row+1);
		range.v2=row-1;
		if (range.v1<0)
			range.v1=0;	
	}
	this->richTextBox2->AppendText(String::Concat(range.v1.ToString()," }-{ ", range.v2.ToString(), "\n"));
//this need to be out some where 
*/
	float MaxV=-99999999999999999.0;
	for (int r=0;r<row;r++){
		float cl=TrainMat->classint[r];
		if (cl > MaxV)
			MaxV=cl;
	}
			 //knn Norm
			 float sum=0.0;
			 

				int k=Convert::ToInt32(this->textBox2->Text);
				for (int i=0;i<TestMat->Row();i++){
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					//calc norm
					float TestNorm=0.0;
					for (int j=0;j<TestMat->Col();j++){
					//	TestNorm+=testRow[j]*testRow[j];
					//	TestNorm+=Math::Pow(2.0,j)*testRow[j];
						TestNorm+=Math::Pow(base,j)*testRow[j];
					}
					//TestNorm=Math::Sqrt(TestNorm);
					//clac range
					range = BinarySearch2values(twovaluesarr, row, TestNorm);
					range.v1=range.v1-Math::Sqrt(row)/4.0;
					range.v2=range.v2+Math::Sqrt(row)/4.0;
					if (range.v1<0){
						range.v2=range.v2+Math::Abs(range.v1);
						range.v1=0;
					}
					if (range.v2>=row){
						range.v1=range.v1-(range.v2-row+1);
						range.v2=row-1;
						if (range.v1<0)
							range.v1=0;	
					}


					int cs=knnNorm(TrainMat,testRow,k,twovaluesarr,range,MaxV);
					this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("KNN Norm: ",sum.ToString());


delete []twovaluesarr; twovaluesarr=0;
		 }
private: System::Void kNNChangeKFrom1ToSqrtNKsWeightsWithIINdxToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //KNN change k from 1 to sqrt n ks weights with inverted indeces 
			 ClassCount=TrainMat->NumberOfClasses();
	float *distance = new float [ClassCount];
	//initilize dist

			
				float sum=0;
				for (int i=0;i<TestMat->Row();i++){
					for (int cls=0;cls<ClassCount;cls++)
						distance[cls]=0.0;
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					for (int k=1;k<= Math::Sqrt(TrainMat->Row());k+=2){			
						int cs=knn(TrainMat,testRow,k);
						distance[cs]+=1.0/(float) k;//Math::Log(1+k,2.0);
						//do inverted inex +=1/k
					}
					int cs=argmax(distance,ClassCount);
					this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("Result knn K=1-sqrt(n)odd ks with IIN weights : ",sum.ToString());
		 delete [] distance; distance=0;

		 }
private: System::Void invertedIndexToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //inverted index 
			 float sum=0;
				for (int i=0;i<TestMat->Row();i++){
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					int cs=InvetedIndeces(TrainMat,testRow);
					this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("IINC Result: ",sum.ToString());

		 }
private: System::Void testKnnWithDifferentKToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	 //knn multi k , multi data sets
		//output file 
		
//open files
	String ^ filename="";
	System::Windows::Forms::DialogResult dresult;
	dresult=ofdlg1->ShowDialog();
	if (dresult ==System::Windows::Forms::DialogResult::OK){
		StreamWriter^ outfile = gcnew StreamWriter("KNN-1-9-tesult.txt");
		this->progressBar1->Maximum=60* ofdlg1->FileNames->Length;
		progressBar1->Value=0;
		//String 
		int f=0;
		for (int f=0;f < ofdlg1->FileNames->Length;f++){
		//for each (filename in ofdlg1->FileNames){
			Application::DoEvents();
				filename=ofdlg1->FileNames[f];

//========
				System::IO::FileInfo  ^fleMembers = gcnew FileInfo(filename);
				StreamReader ^swrMembers = fleMembers->OpenText();
				this->statusStrip1->Text=String::Concat("  Loading File: ,",filename, "For Training...");
				if(trainfile)
					trainfile->Clear();
				else
					trainfile=gcnew ArrayList();
				if(TrainMat){
					delete TrainMat; TrainMat=0;}
				if(TestMat)
					{delete TestMat; TestMat=0;}
				if(testfile)
					testfile->Clear();

	 			String ^line =swrMembers->ReadLine();
				
				String^ delimStr= " ";
				array<Char>^ delimiter = delimStr->ToCharArray( );
				array<String^>^ WordsNumbers;
				WordsNumbers = line->Split(delimiter);
				col=WordsNumbers->Length-1;
				
				while(line){

					trainfile->Add(line);
					line =swrMembers->ReadLine();
				}
				swrMembers->Close();
				
				row=trainfile->Count;
				TrainMat=new Mat(row,col);
				int j;
				for(j=0;j<col;j++){
						TrainMat->set(0,j,Convert::ToDouble(WordsNumbers[j]));
					}
				TrainMat->classint[0] = Convert::ToInt32(WordsNumbers[j]);
				for (int i=1;i<trainfile->Count;i++){
					WordsNumbers->Clear;
					String ^temp= safe_cast <String ^> (trainfile[i])  ;
					WordsNumbers = temp->Split(delimiter);
					for( j=0;j<col;j++){
						TrainMat->set(i,j,Convert::ToDouble(WordsNumbers[j]));
					}
					TrainMat->classint[i] = Convert::ToInt32(WordsNumbers[j]);
				}
				trainfile->Clear();
				
				String ^temp;
				temp= filename->Substring(1+ filename->LastIndexOf("\\"));
				temp=String::Concat(temp, "  Loaded ..:","\n");
				temp=String::Concat(temp,"number of vars: ",(col).ToString(),"\n");
				temp=String::Concat(temp,"number of examples: ",(row).ToString(),"\n");
				temp=String::Concat(temp,"class at column: ",(col+1).ToString(),"\n");
				this->richTextBox2->AppendText(temp);
				outfile->Write(temp);
//end open
//creat sample test file


//end  creat sample test file
//remove random examples from train and insert em into test set
			 if(!TrainMat){
				MessageBox::Show("no train data ..");

				 goto exit_sub;
			 }
//normalize data
if (this->checkBox1->Checked)
	TrainMat->Normalize();

	for (int TestNumer=0; TestNumer <10;TestNumer++){ //repeat the test on different sample
		Application::DoEvents();
		ArrayList ^train=MatToArrayList(TrainMat);
		int row;
		//int i;
		ArrayList ^test;//=gcnew ArrayList ();
		if(TestMat){
				test=MatToArrayList(TestMat);
				 delete TestMat; TestMat=0;
				 int testcount=test->Count;
				 for (int i=0;i<testcount;i++){
					train->Add(test[0]);
					test->RemoveAt(0);
				 }
			 }
			 else
				test=gcnew ArrayList ();



		row=train->Count;
		bool *visited=new bool[row];
		for(int i=0;i<row;i++){
			visited[i]=false;
		}
		//Random ^rnd=gcnew Random(4443);
		float ratio=Convert::ToDouble(this->textBox1->Text);
		int testSize= ratio*row;

		for (int i=0;i<testSize;i++){
nextrnd:
			int rownum=rnd->Next(0,train->Count-1);
			if(visited[rownum])
				goto nextrnd;
			visited[rownum]=true;
			test->Add(train[rownum]);
			train->RemoveAt(rownum);
		}
		delete TrainMat; TrainMat=0;
		delete TestMat; TestMat=0;
		TrainMat=ArrayListToMat(train);
		TestMat=ArrayListToMat(test);
		train->Clear();
		test->Clear();
		
		delete []visited; visited=0;
exit_sub:
		this->richTextBox2->AppendText("\nTest Sample:" + (TestNumer+1).ToString() + "\n" );
		outfile->WriteLine("\nTest Sample:" + (TestNumer+1).ToString() + "\n");
		this->richTextBox2->AppendText("number of test Examples:" + TestMat->Row().ToString() + "\n" );
		outfile->WriteLine("number of test Examples:" + TestMat->Row().ToString() + "\n");


		for (int i=1;i<10;i+=2){
			//do test for each k 
			float sum=0.0;
			int k=i;//Convert::ToInt32(this->textBox2->Text);
			//DistanceType=dist;
			for (int ii=0;ii<TestMat->Row();ii++){
				float *testRow=new float[TestMat->Col()];
				TestMat->getRow(testRow,ii);
				int cs=knn(TrainMat,testRow,k);
				if (TestMat->classint[ii]==cs)
					sum++;
				delete []testRow; testRow=0;
			}
			sum=sum/(float) TestMat->Row();
			sum=Math::Round(sum,4.0);
			String ^temp=String::Concat("K= ",k.ToString(),"\n",comboBox1->Text);
			temp=String::Concat(temp," KNN Result:",sum.ToString(),"\n");
			this->richTextBox2->AppendText(temp);
			outfile->Write(temp);
		progressBar1->Value++;
		}//for each k 

//do it for the sqrt(n)
			float sum=0.0;
			int k=Math::Sqrt(TrainMat->Row());
			//DistanceType=dist;
			for (int ii=0;ii<TestMat->Row();ii++){
				float *testRow=new float[TestMat->Col()];
				TestMat->getRow(testRow,ii);
				int cs=knn(TrainMat,testRow,k);
				if (TestMat->classint[ii]==cs)
					sum++;
				delete []testRow; testRow=0;
			}
			sum=sum/(float) TestMat->Row();
			sum=Math::Round(sum,4.0);
			String ^temp=String::Concat("K= ",k.ToString(),"\n",comboBox1->Text);
			temp=String::Concat(temp," KNN Result:",sum.ToString(),"\n");
			this->richTextBox2->AppendText(temp);
			outfile->Write(temp);
		progressBar1->Value++;

//////////////////



			 }//end for each test number
			this->richTextBox2->AppendText("\n");
			outfile->Write("\n");

}//end for each file
				outfile->Close();

			} //end if for open fil dialog result
		 }
private: System::Void testIINCOnAllDatasetsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //IINC full test

		//output file 
		
//open files
	String ^ filename="";
	System::Windows::Forms::DialogResult dresult;
	dresult=ofdlg1->ShowDialog();
	if (dresult ==System::Windows::Forms::DialogResult::OK){
		Stopwatch ^timer = gcnew Stopwatch();
        timer->Start();

		StreamWriter^ outfile = gcnew StreamWriter("INNC-tesult.txt");
		this->progressBar1->Maximum=10* ofdlg1->FileNames->Length;
		progressBar1->Value=0;
		//String 
		int f=0;
		for (int f=0;f < ofdlg1->FileNames->Length;f++){
		//for each (filename in ofdlg1->FileNames){
			Application::DoEvents();
				filename=ofdlg1->FileNames[f];

//========
				System::IO::FileInfo  ^fleMembers = gcnew FileInfo(filename);
				StreamReader ^swrMembers = fleMembers->OpenText();
				this->statusStrip1->Text=String::Concat("  Loading File: ,",filename, "For Training...");
				if(trainfile)
					trainfile->Clear();
				else
					trainfile=gcnew ArrayList();
				if(TrainMat){
					delete TrainMat; TrainMat=0;}
				if(TestMat)
					{delete TestMat; TestMat=0;}
				if(testfile)
					testfile->Clear();

	 			String ^line =swrMembers->ReadLine();
				
				String^ delimStr= " ";
				array<Char>^ delimiter = delimStr->ToCharArray( );
				array<String^>^ WordsNumbers;
				WordsNumbers = line->Split(delimiter);
				col=WordsNumbers->Length-1;
				
				while(line){

					trainfile->Add(line);
					line =swrMembers->ReadLine();
				}
				swrMembers->Close();
				
				row=trainfile->Count;
				TrainMat=new Mat(row,col);
				int j;
				for(j=0;j<col;j++){
						TrainMat->set(0,j,Convert::ToDouble(WordsNumbers[j]));
					}
				TrainMat->classint[0] = Convert::ToInt32(WordsNumbers[j]);
				for (int i=1;i<trainfile->Count;i++){
					WordsNumbers->Clear;
					String ^temp= safe_cast <String ^> (trainfile[i])  ;
					WordsNumbers = temp->Split(delimiter);
					for( j=0;j<col;j++){
						TrainMat->set(i,j,Convert::ToDouble(WordsNumbers[j]));
					}
					TrainMat->classint[i] = Convert::ToInt32(WordsNumbers[j]);
				}
				trainfile->Clear();
				
				String ^temp;
				temp= filename->Substring(1+ filename->LastIndexOf("\\"));
				temp=String::Concat(temp, "  Loaded ..:","\n");
				temp=String::Concat(temp,"number of vars: ",(col).ToString(),"\n");
				temp=String::Concat(temp,"number of examples: ",(row).ToString(),"\n");
				temp=String::Concat(temp,"class at column: ",(col+1).ToString(),"\n");
				this->richTextBox2->AppendText(temp);
				outfile->Write(temp);
//end open
//creat sample test file


//end  creat sample test file
//remove random examples from train and insert em into test set
			 if(!TrainMat){
				MessageBox::Show("no train data ..");

				 goto exit_sub;
			 }
//normalize data
if (this->checkBox1->Checked)
	TrainMat->Normalize();

	for (int TestNumer=0; TestNumer <10;TestNumer++){ //repeat the test on different sample
		Application::DoEvents();
		ArrayList ^train=MatToArrayList(TrainMat);
		int row;
		//int i;
		ArrayList ^test;//=gcnew ArrayList ();
		if(TestMat){
				test=MatToArrayList(TestMat);
				 delete TestMat; TestMat=0;
				 int testcount=test->Count;
				 for (int i=0;i<testcount;i++){
					train->Add(test[0]);
					test->RemoveAt(0);
				 }
			 }
			 else
				test=gcnew ArrayList ();



		row=train->Count;
		bool *visited=new bool[row];
		for(int i=0;i<row;i++){
			visited[i]=false;
		}
		//Random ^rnd=gcnew Random(4443);
		float ratio=Convert::ToDouble(this->textBox1->Text);
		int testSize= ratio*row;

		for (int i=0;i<testSize;i++){
nextrnd:
			int rownum=rnd->Next(0,train->Count-1);
			if(visited[rownum])
				goto nextrnd;
			visited[rownum]=true;
			test->Add(train[rownum]);
			train->RemoveAt(rownum);
		}
		delete TrainMat; TrainMat=0;
		delete TestMat; TestMat=0;
		TrainMat=ArrayListToMat(train);
		TestMat=ArrayListToMat(test);
		train->Clear();
		test->Clear();
		
		delete []visited; visited=0;
exit_sub:
		this->richTextBox2->AppendText("\nTest Sample:" + (TestNumer+1).ToString() + "\n" );
		outfile->WriteLine("\nTest Sample:" + (TestNumer+1).ToString() + "\n");
		this->richTextBox2->AppendText("number of test Examples:" + TestMat->Row().ToString() + "\n" );
		outfile->WriteLine("number of test Examples:" + TestMat->Row().ToString() + "\n");




//do it for the IINC
			float sum=0.0;
			for (int ii=0;ii<TestMat->Row();ii++){
				float *testRow=new float[TestMat->Col()];
				TestMat->getRow(testRow,ii);
				int cs=InvetedIndeces(TrainMat,testRow);
				if (TestMat->classint[ii]==cs)
					sum++;
				delete []testRow; testRow=0;
			}
			sum=sum/(float) TestMat->Row();
			sum=Math::Round(sum,4.0);
			String ^temp=String::Concat("\n",comboBox1->Text);
			temp=String::Concat(temp," KNN Result:",sum.ToString(),"\n");
			this->richTextBox2->AppendText(temp);
			outfile->Write(temp);
		progressBar1->Value++;

//////////////////



			 }//end for each test number
			this->richTextBox2->AppendText("\n");
			outfile->Write("\n");

}//end for each file
				outfile->Close();
			timer->Stop();
            String ^temp = timer->ElapsedMilliseconds.ToString();
			this->richTextBox2->AppendText(String::Concat("time Elapsed IINC:",temp,"\n"));

			} //end if for open fil dialog result


		 }
private: System::Void testKNNChangeKFrom1ToSqrtNOddWeightsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
//open files
	String ^ filename="";
	System::Windows::Forms::DialogResult dresult;
	dresult=ofdlg1->ShowDialog();
	if (dresult ==System::Windows::Forms::DialogResult::OK){
		StreamWriter^ outfile = gcnew StreamWriter("KNN kFrom-1-to-SqrtN-Weights-esult.txt");
		this->progressBar1->Maximum=10* ofdlg1->FileNames->Length;
		progressBar1->Value=0;
		//String 
		int f=0;
		for (int f=0;f < ofdlg1->FileNames->Length;f++){
		//for each (filename in ofdlg1->FileNames){
			Application::DoEvents();
				filename=ofdlg1->FileNames[f];

//========
				System::IO::FileInfo  ^fleMembers = gcnew FileInfo(filename);
				StreamReader ^swrMembers = fleMembers->OpenText();
				this->statusStrip1->Text=String::Concat("  Loading File: ,",filename, "For Training...");
				if(trainfile)
					trainfile->Clear();
				else
					trainfile=gcnew ArrayList();
				if(TrainMat){
					delete TrainMat; TrainMat=0;}
				if(TestMat)
					{delete TestMat; TestMat=0;}
				if(testfile)
					testfile->Clear();

	 			String ^line =swrMembers->ReadLine();
				
				String^ delimStr= " ";
				array<Char>^ delimiter = delimStr->ToCharArray( );
				array<String^>^ WordsNumbers;
				WordsNumbers = line->Split(delimiter);
				col=WordsNumbers->Length-1;
				
				while(line){

					trainfile->Add(line);
					line =swrMembers->ReadLine();
				}
				swrMembers->Close();
				
				row=trainfile->Count;
				TrainMat=new Mat(row,col);
				int j;
				for(j=0;j<col;j++){
						TrainMat->set(0,j,Convert::ToDouble(WordsNumbers[j]));
					}
				TrainMat->classint[0] = Convert::ToInt32(WordsNumbers[j]);
				for (int i=1;i<trainfile->Count;i++){
					WordsNumbers->Clear;
					String ^temp= safe_cast <String ^> (trainfile[i])  ;
					WordsNumbers = temp->Split(delimiter);
					for( j=0;j<col;j++){
						TrainMat->set(i,j,Convert::ToDouble(WordsNumbers[j]));
					}
					TrainMat->classint[i] = Convert::ToInt32(WordsNumbers[j]);
				}
				trainfile->Clear();
				
				String ^temp;
				temp= filename->Substring(1+ filename->LastIndexOf("\\"));
				temp=String::Concat(temp, "  Loaded ..:","\n");
				temp=String::Concat(temp,"number of vars: ",(col).ToString(),"\n");
				temp=String::Concat(temp,"number of examples: ",(row).ToString(),"\n");
				temp=String::Concat(temp,"class at column: ",(col+1).ToString(),"\n");
				this->richTextBox2->AppendText(temp);
				outfile->Write(temp);
//end open
//creat sample test file


//end  creat sample test file
//remove random examples from train and insert em into test set
			 if(!TrainMat){
				MessageBox::Show("no train data ..");

				 goto exit_sub;
			 }
//normalize data
if (this->checkBox1->Checked)
	TrainMat->Normalize();

	for (int TestNumer=0; TestNumer <10;TestNumer++){ //repeat the test on different sample
		Application::DoEvents();
		ArrayList ^train=MatToArrayList(TrainMat);
		int row;
		//int i;
		ArrayList ^test;//=gcnew ArrayList ();
		if(TestMat){
				test=MatToArrayList(TestMat);
				 delete TestMat; TestMat=0;
				 int testcount=test->Count;
				 for (int i=0;i<testcount;i++){
					train->Add(test[0]);
					test->RemoveAt(0);
				 }
			 }
			 else
				test=gcnew ArrayList ();



		row=train->Count;
		bool *visited=new bool[row];
		for(int i=0;i<row;i++){
			visited[i]=false;
		}
		//Random ^rnd=gcnew Random(4443);
		float ratio=Convert::ToDouble(this->textBox1->Text);
		int testSize= ratio*row;

		for (int i=0;i<testSize;i++){
nextrnd:
			int rownum=rnd->Next(0,train->Count-1);
			if(visited[rownum])
				goto nextrnd;
			visited[rownum]=true;
			test->Add(train[rownum]);
			train->RemoveAt(rownum);
		}
		delete TrainMat; TrainMat=0;
		delete TestMat; TestMat=0;
		TrainMat=ArrayListToMat(train);
		TestMat=ArrayListToMat(test);
		train->Clear();
		test->Clear();
		
		delete []visited; visited=0;
exit_sub:
		this->richTextBox2->AppendText("\nTest Sample:" + (TestNumer+1).ToString() + "\n" );
		outfile->WriteLine("\nTest Sample:" + (TestNumer+1).ToString() + "\n");
		this->richTextBox2->AppendText("number of test Examples:" + TestMat->Row().ToString() + "\n" );
		outfile->WriteLine("number of test Examples:" + TestMat->Row().ToString() + "\n");




//do it for the change k from 1 to sqrt N weights

	ClassCount=TrainMat->NumberOfClasses();
	float *distance = new float [ClassCount];
	//initilize dist	
				float sum=0;
				for (int i=0;i<TestMat->Row();i++){
					for (int cls=0;cls<ClassCount;cls++)
						distance[cls]=0.0;
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					for (int k=1;k<= Math::Sqrt(TrainMat->Row());k+=2){			
						int cs=knn(TrainMat,testRow,k);
						distance[cs]+=1.0/Math::Log(1+k,2.0);
						//do inverted inex +=1/k
					}
					int cs=argmax(distance,ClassCount);
					this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			String ^temp=String::Concat("\n",comboBox1->Text);
			temp=String::Concat(temp," Result knn K=1-sqrt(n)odd ks with weights:",sum.ToString(),"\n");
			this->richTextBox2->AppendText(temp);
			outfile->Write(temp);
		 delete [] distance; distance=0;
		progressBar1->Value++;

//////////////////



	}//end for each test number
			this->richTextBox2->AppendText("\n");
			outfile->Write("\n");

}//end for each file
				outfile->Close();

			} //end if for open fil dialog result

		 }
private: System::Void testKNNChangeKFrom1ToHalfSqrtNOddWeightsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
//open files
	String ^ filename="";
	System::Windows::Forms::DialogResult dresult;
	dresult=ofdlg1->ShowDialog();
	if (dresult ==System::Windows::Forms::DialogResult::OK){
		StreamWriter^ outfile = gcnew StreamWriter("KNN kFrom-1-to-SqrtN-Weights-esult.txt");
		this->progressBar1->Maximum=10* ofdlg1->FileNames->Length;
		progressBar1->Value=0;
		//String 
		int f=0;
		for (int f=0;f < ofdlg1->FileNames->Length;f++){
		//for each (filename in ofdlg1->FileNames){
			Application::DoEvents();
				filename=ofdlg1->FileNames[f];

//========
				System::IO::FileInfo  ^fleMembers = gcnew FileInfo(filename);
				StreamReader ^swrMembers = fleMembers->OpenText();
				this->statusStrip1->Text=String::Concat("  Loading File: ,",filename, "For Training...");
				if(trainfile)
					trainfile->Clear();
				else
					trainfile=gcnew ArrayList();
				if(TrainMat){
					delete TrainMat; TrainMat=0;}
				if(TestMat)
					{delete TestMat; TestMat=0;}
				if(testfile)
					testfile->Clear();

	 			String ^line =swrMembers->ReadLine();
				
				String^ delimStr= " ";
				array<Char>^ delimiter = delimStr->ToCharArray( );
				array<String^>^ WordsNumbers;
				WordsNumbers = line->Split(delimiter);
				col=WordsNumbers->Length-1;
				
				while(line){

					trainfile->Add(line);
					line =swrMembers->ReadLine();
				}
				swrMembers->Close();
				
				row=trainfile->Count;
				TrainMat=new Mat(row,col);
				int j;
				for(j=0;j<col;j++){
						TrainMat->set(0,j,Convert::ToDouble(WordsNumbers[j]));
					}
				TrainMat->classint[0] = Convert::ToInt32(WordsNumbers[j]);
				for (int i=1;i<trainfile->Count;i++){
					WordsNumbers->Clear;
					String ^temp= safe_cast <String ^> (trainfile[i])  ;
					WordsNumbers = temp->Split(delimiter);
					for( j=0;j<col;j++){
						TrainMat->set(i,j,Convert::ToDouble(WordsNumbers[j]));
					}
					TrainMat->classint[i] = Convert::ToInt32(WordsNumbers[j]);
				}
				trainfile->Clear();
				
				String ^temp;
				temp= filename->Substring(1+ filename->LastIndexOf("\\"));
				temp=String::Concat(temp, "  Loaded ..:","\n");
				temp=String::Concat(temp,"number of vars: ",(col).ToString(),"\n");
				temp=String::Concat(temp,"number of examples: ",(row).ToString(),"\n");
				temp=String::Concat(temp,"class at column: ",(col+1).ToString(),"\n");
				this->richTextBox2->AppendText(temp);
				outfile->Write(temp);
//end open
//creat sample test file


//end  creat sample test file
//remove random examples from train and insert em into test set
			 if(!TrainMat){
				MessageBox::Show("no train data ..");

				 goto exit_sub;
			 }
//normalize data
if (this->checkBox1->Checked)
	TrainMat->Normalize();

	for (int TestNumer=0; TestNumer <10;TestNumer++){ //repeat the test on different sample
		Application::DoEvents();
		ArrayList ^train=MatToArrayList(TrainMat);
		int row;
		//int i;
		ArrayList ^test;//=gcnew ArrayList ();
		if(TestMat){
				test=MatToArrayList(TestMat);
				 delete TestMat; TestMat=0;
				 int testcount=test->Count;
				 for (int i=0;i<testcount;i++){
					train->Add(test[0]);
					test->RemoveAt(0);
				 }
			 }
			 else
				test=gcnew ArrayList ();



		row=train->Count;
		bool *visited=new bool[row];
		for(int i=0;i<row;i++){
			visited[i]=false;
		}
		//Random ^rnd=gcnew Random(4443);
		float ratio=Convert::ToDouble(this->textBox1->Text);
		int testSize= ratio*row;

		for (int i=0;i<testSize;i++){
nextrnd:
			int rownum=rnd->Next(0,train->Count-1);
			if(visited[rownum])
				goto nextrnd;
			visited[rownum]=true;
			test->Add(train[rownum]);
			train->RemoveAt(rownum);
		}
		delete TrainMat; TrainMat=0;
		delete TestMat; TestMat=0;
		TrainMat=ArrayListToMat(train);
		TestMat=ArrayListToMat(test);
		train->Clear();
		test->Clear();
		
		delete []visited; visited=0;
exit_sub:
		this->richTextBox2->AppendText("\nTest Sample:" + (TestNumer+1).ToString() + "\n" );
		outfile->WriteLine("\nTest Sample:" + (TestNumer+1).ToString() + "\n");
		this->richTextBox2->AppendText("number of test Examples:" + TestMat->Row().ToString() + "\n" );
		outfile->WriteLine("number of test Examples:" + TestMat->Row().ToString() + "\n");




//do it for the change k from 1 to sqrt N weights

	ClassCount=TrainMat->NumberOfClasses();
	float *distance = new float [ClassCount];
	//initilize dist	
				float sum=0;
				for (int i=0;i<TestMat->Row();i++){
					for (int cls=0;cls<ClassCount;cls++)
						distance[cls]=0.0;
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					for (int k=1;k<= Math::Sqrt(TrainMat->Row())/2.0;k+=2){			
						int cs=knn(TrainMat,testRow,k);
						distance[cs]+=1.0/Math::Log(1+k,2.0);
						//do inverted inex +=1/k
					}
					int cs=argmax(distance,ClassCount);
					this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			String ^temp=String::Concat("\n",comboBox1->Text);
			temp=String::Concat(temp," Result knn K=1- Half sqrt(n)odd ks with weights:",sum.ToString(),"\n");
			this->richTextBox2->AppendText(temp);
			outfile->Write(temp);
		 delete [] distance; distance=0;
		progressBar1->Value++;

//////////////////



	}//end for each test number
			this->richTextBox2->AppendText("\n");
			outfile->Write("\n");

}//end for each file
				outfile->Close();

			} //end if for open fil dialog result

		 }

private: System::Void testKNNKfrom1ToSrtnOddWeightsNewToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
//knn K=1-sqrt(n)odd ks with weights new
			 //open files
	String ^ filename="";
	System::Windows::Forms::DialogResult dresult;
	dresult=ofdlg1->ShowDialog();
	if (dresult ==System::Windows::Forms::DialogResult::OK){
		Stopwatch ^timer = gcnew Stopwatch();
        timer->Start();
		StreamWriter^ outfile = gcnew StreamWriter("KNN kFrom-1-to-SqrtN-Weights-esult.txt");
		this->progressBar1->Maximum=10* ofdlg1->FileNames->Length;
		progressBar1->Value=0;
		//String 
		int f=0;
		for (int f=0;f < ofdlg1->FileNames->Length;f++){
		//for each (filename in ofdlg1->FileNames){
			Application::DoEvents();
				filename=ofdlg1->FileNames[f];

//========
				System::IO::FileInfo  ^fleMembers = gcnew FileInfo(filename);
				StreamReader ^swrMembers = fleMembers->OpenText();
				this->statusStrip1->Text=String::Concat("  Loading File: ,",filename, "For Training...");
				if(trainfile)
					trainfile->Clear();
				else
					trainfile=gcnew ArrayList();
				if(TrainMat){
					delete TrainMat; TrainMat=0;}
				if(TestMat)
					{delete TestMat; TestMat=0;}
				if(testfile)
					testfile->Clear();

	 			String ^line =swrMembers->ReadLine();
				
				String^ delimStr= " ";
				array<Char>^ delimiter = delimStr->ToCharArray( );
				array<String^>^ WordsNumbers;
				WordsNumbers = line->Split(delimiter);
				col=WordsNumbers->Length-1;
				
				while(line){

					trainfile->Add(line);
					line =swrMembers->ReadLine();
				}
				swrMembers->Close();
				
				row=trainfile->Count;
				TrainMat=new Mat(row,col);
				int j;
				for(j=0;j<col;j++){
						TrainMat->set(0,j,Convert::ToDouble(WordsNumbers[j]));
					}
				TrainMat->classint[0] = Convert::ToInt32(WordsNumbers[j]);
				for (int i=1;i<trainfile->Count;i++){
					WordsNumbers->Clear;
					String ^temp= safe_cast <String ^> (trainfile[i])  ;
					WordsNumbers = temp->Split(delimiter);
					for( j=0;j<col;j++){
						TrainMat->set(i,j,Convert::ToDouble(WordsNumbers[j]));
					}
					TrainMat->classint[i] = Convert::ToInt32(WordsNumbers[j]);
				}
				trainfile->Clear();
				
				String ^temp;
				temp= filename->Substring(1+ filename->LastIndexOf("\\"));
				temp=String::Concat(temp, "  Loaded ..:","\n");
				temp=String::Concat(temp,"number of vars: ",(col).ToString(),"\n");
				temp=String::Concat(temp,"number of examples: ",(row).ToString(),"\n");
				temp=String::Concat(temp,"class at column: ",(col+1).ToString(),"\n");
				this->richTextBox2->AppendText(temp);
				outfile->Write(temp);
//end open
//creat sample test file


//end  creat sample test file
//remove random examples from train and insert em into test set
			 if(!TrainMat){
				MessageBox::Show("no train data ..");

				 goto exit_sub;
			 }
//normalize data
if (this->checkBox1->Checked)
	TrainMat->Normalize();

	for (int TestNumer=0; TestNumer <10;TestNumer++){ //repeat the test on different sample
		Application::DoEvents();
		ArrayList ^train=MatToArrayList(TrainMat);
		int row;
		//int i;
		ArrayList ^test;//=gcnew ArrayList ();
		if(TestMat){
				test=MatToArrayList(TestMat);
				 delete TestMat; TestMat=0;
				 int testcount=test->Count;
				 for (int i=0;i<testcount;i++){
					train->Add(test[0]);
					test->RemoveAt(0);
				 }
			 }
			 else
				test=gcnew ArrayList ();



		row=train->Count;
		bool *visited=new bool[row];
		for(int i=0;i<row;i++){
			visited[i]=false;
		}
		//Random ^rnd=gcnew Random(4443);
		float ratio=Convert::ToDouble(this->textBox1->Text);
		int testSize= ratio*row;

		for (int i=0;i<testSize;i++){
nextrnd:
			int rownum=rnd->Next(0,train->Count-1);
			if(visited[rownum])
				goto nextrnd;
			visited[rownum]=true;
			test->Add(train[rownum]);
			train->RemoveAt(rownum);
		}
		delete TrainMat; TrainMat=0;
		delete TestMat; TestMat=0;
		TrainMat=ArrayListToMat(train);
		TestMat=ArrayListToMat(test);
		train->Clear();
		test->Clear();
		
		delete []visited; visited=0;
exit_sub:
		this->richTextBox2->AppendText("\nTest Sample:" + (TestNumer+1).ToString() + "\n" );
		outfile->WriteLine("\nTest Sample:" + (TestNumer+1).ToString() + "\n");
		this->richTextBox2->AppendText("number of test Examples:" + TestMat->Row().ToString() + "\n" );
		outfile->WriteLine("number of test Examples:" + TestMat->Row().ToString() + "\n");




//do it for the change k from 1 to sqrt N weights

	/*ClassCount=TrainMat->NumberOfClasses();
	double *distance = new double [ClassCount];*/
	//initilize dist	
				float sum=0;
				for (int i=0;i<TestMat->Row();i++){
					/*for (int cls=0;cls<ClassCount;cls++)
						distance[cls]=0.0;*/
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
				/*	for (int k=1;k<= Math::Sqrt(TrainMat->Row());k+=2){			
						int cs=knn(TrainMat,testRow,k);
						distance[cs]+=1.0/Math::Log(1+k,2.0);
						//do inverted inex +=1/k
					}
					int cs=argmax(distance,ClassCount);*/
					int k=Math::Sqrt(TrainMat->Row());
					int cs=Ensimbleknn(TrainMat,testRow,k);
					
				//	this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			String ^temp=String::Concat("\n",comboBox1->Text);
			temp=String::Concat(temp," Result knn K=1-sqrt(n)odd ks with weights new:",sum.ToString(),"\n");
			this->richTextBox2->AppendText(temp);
			outfile->Write(temp);
		// delete [] distance; distance=0;
		progressBar1->Value++;

//////////////////



	}//end for each test number
			this->richTextBox2->AppendText("\n");
			outfile->Write("\n");

}//end for each file
				outfile->Close();
			timer->Stop();
            String ^temp = timer->ElapsedMilliseconds.ToString();
			this->richTextBox2->AppendText(String::Concat("time Elapsed proposed:",temp,"\n"));
			} //end if for open fil dialog result
		 }
private: System::Void testKnnWithK304560ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	 //knn multi k 30 45 60, multi data sets
		//output file 
		
//open files
	String ^ filename="";
	System::Windows::Forms::DialogResult dresult;
	dresult=ofdlg1->ShowDialog();
	if (dresult ==System::Windows::Forms::DialogResult::OK){
		StreamWriter^ outfile = gcnew StreamWriter("KNN-30-45-60tesult.txt");
		this->progressBar1->Maximum=60* ofdlg1->FileNames->Length;
		progressBar1->Value=0;
		//String 
		int f=0;
		for (int f=0;f < ofdlg1->FileNames->Length;f++){
		//for each (filename in ofdlg1->FileNames){
			Application::DoEvents();
				filename=ofdlg1->FileNames[f];

//========
				System::IO::FileInfo  ^fleMembers = gcnew FileInfo(filename);
				StreamReader ^swrMembers = fleMembers->OpenText();
				this->statusStrip1->Text=String::Concat("  Loading File: ,",filename, "For Training...");
				if(trainfile)
					trainfile->Clear();
				else
					trainfile=gcnew ArrayList();
				if(TrainMat){
					delete TrainMat; TrainMat=0;}
				if(TestMat)
					{delete TestMat; TestMat=0;}
				if(testfile)
					testfile->Clear();

	 			String ^line =swrMembers->ReadLine();
				
				String^ delimStr= " ";
				array<Char>^ delimiter = delimStr->ToCharArray( );
				array<String^>^ WordsNumbers;
				WordsNumbers = line->Split(delimiter);
				col=WordsNumbers->Length-1;
				
				while(line){

					trainfile->Add(line);
					line =swrMembers->ReadLine();
				}
				swrMembers->Close();
				
				row=trainfile->Count;
				TrainMat=new Mat(row,col);
				int j;
				for(j=0;j<col;j++){
						TrainMat->set(0,j,Convert::ToDouble(WordsNumbers[j]));
					}
				TrainMat->classint[0] = Convert::ToInt32(WordsNumbers[j]);
				for (int i=1;i<trainfile->Count;i++){
					WordsNumbers->Clear;
					String ^temp= safe_cast <String ^> (trainfile[i])  ;
					WordsNumbers = temp->Split(delimiter);
					for( j=0;j<col;j++){
						TrainMat->set(i,j,Convert::ToDouble(WordsNumbers[j]));
					}
					TrainMat->classint[i] = Convert::ToInt32(WordsNumbers[j]);
				}
				trainfile->Clear();
				
				String ^temp;
				temp= filename->Substring(1+ filename->LastIndexOf("\\"));
				temp=String::Concat(temp, "  Loaded ..:","\n");
				temp=String::Concat(temp,"number of vars: ",(col).ToString(),"\n");
				temp=String::Concat(temp,"number of examples: ",(row).ToString(),"\n");
				temp=String::Concat(temp,"class at column: ",(col+1).ToString(),"\n");
				this->richTextBox2->AppendText(temp);
				outfile->Write(temp);
//end open
//creat sample test file


//end  creat sample test file
//remove random examples from train and insert em into test set
			 if(!TrainMat){
				MessageBox::Show("no train data ..");

				 goto exit_sub;
			 }
//normalize data
if (this->checkBox1->Checked)
	TrainMat->Normalize();

	for (int TestNumer=0; TestNumer <10;TestNumer++){ //repeat the test on different sample
		Application::DoEvents();
		ArrayList ^train=MatToArrayList(TrainMat);
		int row;
		//int i;
		ArrayList ^test;//=gcnew ArrayList ();
		if(TestMat){
				test=MatToArrayList(TestMat);
				 delete TestMat; TestMat=0;
				 int testcount=test->Count;
				 for (int i=0;i<testcount;i++){
					train->Add(test[0]);
					test->RemoveAt(0);
				 }
			 }
			 else
				test=gcnew ArrayList ();



		row=train->Count;
		bool *visited=new bool[row];
		for(int i=0;i<row;i++){
			visited[i]=false;
		}
		//Random ^rnd=gcnew Random(4443);
		float ratio=Convert::ToDouble(this->textBox1->Text);
		int testSize= ratio*row;

		for (int i=0;i<testSize;i++){
nextrnd:
			int rownum=rnd->Next(0,train->Count-1);
			if(visited[rownum])
				goto nextrnd;
			visited[rownum]=true;
			test->Add(train[rownum]);
			train->RemoveAt(rownum);
		}
		delete TrainMat; TrainMat=0;
		delete TestMat; TestMat=0;
		TrainMat=ArrayListToMat(train);
		TestMat=ArrayListToMat(test);
		train->Clear();
		test->Clear();
		
		delete []visited; visited=0;
exit_sub:
		this->richTextBox2->AppendText("\nTest Sample:" + (TestNumer+1).ToString() + "\n" );
		outfile->WriteLine("\nTest Sample:" + (TestNumer+1).ToString() + "\n");
		this->richTextBox2->AppendText("number of test Examples:" + TestMat->Row().ToString() + "\n" );
		outfile->WriteLine("number of test Examples:" + TestMat->Row().ToString() + "\n");


		for (int i=30;i<=60;i+=15){
			//do test for each k 
			float sum=0.0;
			int k=i;//Convert::ToInt32(this->textBox2->Text);
			//DistanceType=dist;
			for (int ii=0;ii<TestMat->Row();ii++){
				float *testRow=new float[TestMat->Col()];
				TestMat->getRow(testRow,ii);
				int cs=knn(TrainMat,testRow,k);
				if (TestMat->classint[ii]==cs)
					sum++;
				delete []testRow; testRow=0;
			}
			sum=sum/(float) TestMat->Row();
			sum=Math::Round(sum,4.0);
			String ^temp=String::Concat("K= ",k.ToString(),"\n",comboBox1->Text);
			temp=String::Concat(temp," KNN Result:",sum.ToString(),"\n");
			this->richTextBox2->AppendText(temp);
			outfile->Write(temp);
		progressBar1->Value++;
		}//for each k 

			 }//end for each test number
			this->richTextBox2->AppendText("\n");
			outfile->Write("\n");

}//end for each file
				outfile->Close();

			} //end if for open fil dialog result
		 }
private: System::Void knnOddEightsNewWithDistanceToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //with weighted distance
//knn K=1-sqrt(n)odd ks with weights new
			 //open files
	String ^ filename="";
	System::Windows::Forms::DialogResult dresult;
	dresult=ofdlg1->ShowDialog();
	if (dresult ==System::Windows::Forms::DialogResult::OK){
		Stopwatch ^timer = gcnew Stopwatch();
        timer->Start();
		StreamWriter^ outfile = gcnew StreamWriter("KNN kFrom-1-to-SqrtN-Weights-esult.txt");
		this->progressBar1->Maximum=10* ofdlg1->FileNames->Length;
		progressBar1->Value=0;
		//String 
		int f=0;
		for (int f=0;f < ofdlg1->FileNames->Length;f++){
		//for each (filename in ofdlg1->FileNames){
			Application::DoEvents();
				filename=ofdlg1->FileNames[f];

//========
				System::IO::FileInfo  ^fleMembers = gcnew FileInfo(filename);
				StreamReader ^swrMembers = fleMembers->OpenText();
				this->statusStrip1->Text=String::Concat("  Loading File: ,",filename, "For Training...");
				if(trainfile)
					trainfile->Clear();
				else
					trainfile=gcnew ArrayList();
				if(TrainMat){
					delete TrainMat; TrainMat=0;}
				if(TestMat)
					{delete TestMat; TestMat=0;}
				if(testfile)
					testfile->Clear();

	 			String ^line =swrMembers->ReadLine();
				
				String^ delimStr= " ";
				array<Char>^ delimiter = delimStr->ToCharArray( );
				array<String^>^ WordsNumbers;
				WordsNumbers = line->Split(delimiter);
				col=WordsNumbers->Length-1;
				
				while(line){

					trainfile->Add(line);
					line =swrMembers->ReadLine();
				}
				swrMembers->Close();
				
				row=trainfile->Count;
				TrainMat=new Mat(row,col);
				int j;
				for(j=0;j<col;j++){
						TrainMat->set(0,j,Convert::ToDouble(WordsNumbers[j]));
					}
				TrainMat->classint[0] = Convert::ToInt32(WordsNumbers[j]);
				for (int i=1;i<trainfile->Count;i++){
					WordsNumbers->Clear;
					String ^temp= safe_cast <String ^> (trainfile[i])  ;
					WordsNumbers = temp->Split(delimiter);
					for( j=0;j<col;j++){
						TrainMat->set(i,j,Convert::ToDouble(WordsNumbers[j]));
					}
					TrainMat->classint[i] = Convert::ToInt32(WordsNumbers[j]);
				}
				trainfile->Clear();
				
				String ^temp;
				temp= filename->Substring(1+ filename->LastIndexOf("\\"));
				temp=String::Concat(temp, "  Loaded ..:","\n");
				temp=String::Concat(temp,"number of vars: ",(col).ToString(),"\n");
				temp=String::Concat(temp,"number of examples: ",(row).ToString(),"\n");
				temp=String::Concat(temp,"class at column: ",(col+1).ToString(),"\n");
				this->richTextBox2->AppendText(temp);
				outfile->Write(temp);
//end open
//creat sample test file


//end  creat sample test file
//remove random examples from train and insert em into test set
			 if(!TrainMat){
				MessageBox::Show("no train data ..");

				 goto exit_sub;
			 }
//normalize data
if (this->checkBox1->Checked)
	TrainMat->Normalize();

	for (int TestNumer=0; TestNumer <10;TestNumer++){ //repeat the test on different sample
		Application::DoEvents();
		ArrayList ^train=MatToArrayList(TrainMat);
		int row;
		//int i;
		ArrayList ^test;//=gcnew ArrayList ();
		if(TestMat){
				test=MatToArrayList(TestMat);
				 delete TestMat; TestMat=0;
				 int testcount=test->Count;
				 for (int i=0;i<testcount;i++){
					train->Add(test[0]);
					test->RemoveAt(0);
				 }
			 }
			 else
				test=gcnew ArrayList ();



		row=train->Count;
		bool *visited=new bool[row];
		for(int i=0;i<row;i++){
			visited[i]=false;
		}
		//Random ^rnd=gcnew Random(4443);
		float ratio=Convert::ToDouble(this->textBox1->Text);
		int testSize= ratio*row;

		for (int i=0;i<testSize;i++){
nextrnd:
			int rownum=rnd->Next(0,train->Count-1);
			if(visited[rownum])
				goto nextrnd;
			visited[rownum]=true;
			test->Add(train[rownum]);
			train->RemoveAt(rownum);
		}
		delete TrainMat; TrainMat=0;
		delete TestMat; TestMat=0;
		TrainMat=ArrayListToMat(train);
		TestMat=ArrayListToMat(test);
		train->Clear();
		test->Clear();
		
		delete []visited; visited=0;
exit_sub:
		this->richTextBox2->AppendText("\nTest Sample:" + (TestNumer+1).ToString() + "\n" );
		outfile->WriteLine("\nTest Sample:" + (TestNumer+1).ToString() + "\n");
		this->richTextBox2->AppendText("number of test Examples:" + TestMat->Row().ToString() + "\n" );
		outfile->WriteLine("number of test Examples:" + TestMat->Row().ToString() + "\n");




//do it for the change k from 1 to sqrt N weights

	/*ClassCount=TrainMat->NumberOfClasses();
	double *distance = new double [ClassCount];*/
	//initilize dist	
				float sum=0;
				for (int i=0;i<TestMat->Row();i++){
					/*for (int cls=0;cls<ClassCount;cls++)
						distance[cls]=0.0;*/
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
				/*	for (int k=1;k<= Math::Sqrt(TrainMat->Row());k+=2){			
						int cs=knn(TrainMat,testRow,k);
						distance[cs]+=1.0/Math::Log(1+k,2.0);
						//do inverted inex +=1/k
					}
					int cs=argmax(distance,ClassCount);*/
					int k=Math::Sqrt(TrainMat->Row());
					int cs=EnsimbleknnWDsitance(TrainMat,testRow,k);
					
				//	this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			String ^temp=String::Concat("\n",comboBox1->Text);
			temp=String::Concat(temp," Result knn K=1-sqrt(n)odd ks with weights new:",sum.ToString(),"\n");
			this->richTextBox2->AppendText(temp);
			outfile->Write(temp);
		// delete [] distance; distance=0;
		progressBar1->Value++;

//////////////////



	}//end for each test number
			this->richTextBox2->AppendText("\n");
			outfile->Write("\n");

}//end for each file
				outfile->Close();
			timer->Stop();
            String ^temp = timer->ElapsedMilliseconds.ToString();
			this->richTextBox2->AppendText(String::Concat("time Elapsed proposed:",temp,"\n"));
			} //end if for open fil dialog result

		 }
private: System::Void kNFToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //k nearest feature
			 float sum=0;
				int k=Convert::ToInt32(this->textBox2->Text);
				for (int i=0;i<TestMat->Row();i++){
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					int cs=knf(TrainMat,testRow,k);
					this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("KNf Result: ",sum.ToString());

		 }
private: System::Void ensimbleIINCToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //ensimble IINC
			 
			 float sum=0;
				for (int i=0;i<TestMat->Row();i++){
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					int cs=EnsimbleIINC(TrainMat,testRow);
					this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("Ensimble IINC Result: ",sum.ToString());

		 }
private: System::Void reduceFeaturesByHalfToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //reduce features by half
		ArrayList ^train=MatToArrayList(TrainMat);
		delete TrainMat;	TrainMat=0;
		float ratio=Convert::ToDouble(this->textBox3->Text);
		ArrayList ^train2=ArrayListMergeFeatures(train,ratio);
		TrainMat=ArrayListToMat(train2);


		 }
private: System::Void trainWeightsUsingChiToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		 }
private: System::Void clacMaxValuesInMatrixToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			TrainMat->setMaxes();

		 }
private: System::Void tanhTestToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 float count=Convert::ToDouble(this->textBox2->Text);
			 float distance;
			 for (int r=-count;r<=count;r++){
				this->richTextBox1->AppendText("\t" + r.ToString());
			 }
			this->richTextBox1->AppendText("\n");
			 for (int r=-count;r<=count;r++){
				 String ^str=gcnew String(r.ToString());
				for (int c=-count;c<=count;c++){
					 distance= Math::Tanh((2.0*count)*Math::Abs(r-c));

					str=String::Concat(str,"\t",distance.ToString());
				}
				str=String::Concat(str,"\n");
				this->richTextBox1->AppendText(str);
			 }
			 this->richTextBox1->AppendText(Math::Pow(2.0,1000.0).ToString());
			
		 }
private: System::Void minMaxNewToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 float count=Convert::ToDouble(this->textBox2->Text);
			 float distance;
			 for (int r=-count;r<=count;r++){
				this->richTextBox1->AppendText("\t" + r.ToString());
			 }
			this->richTextBox1->AppendText("\n");
			 float eps=2*count;
			// float eps=count;
			 for (int r=-count;r<=count;r++){
				 String ^str=gcnew String(r.ToString());
				for (int c=-count;c<=count;c++){
					(Math::Min(r,c)<0) ? 
						/*distance= 1.0 -
						(1+ Math::Min(r,c)+ Math::Abs(Math::Min(r,c)))/
					    (float) (1+ Math::Max(r,c)+ Math::Abs(Math::Min(r,c)))
						: distance= 1.0 -(1+ Math::Min(r,c))/(float)(1+ Math::Max(r,c));*/

						distance= 1.0 -
						(eps+ Math::Min(r,c)+ Math::Abs(Math::Min(r,c)))/
					    (float) (eps+ Math::Max(r,c)+ Math::Abs(Math::Min(r,c)))
						: distance= 1.0 -(eps+ Math::Min(r,c))/(float)(eps+ Math::Max(r,c));
					distance*=2.0;

					str=String::Concat(str,"\t",distance.ToString());
				}
				str=String::Concat(str,"\n");
				this->richTextBox1->AppendText(str);
			 }

		 }
//===========
void  SetRange(){
			 if (Range){
				 delete [] Range;
				 Range=0;
			 }
			 int col=TrainMat->Col();
			 int row=TrainMat->Row();
			 Range = new float [col];
			 for (int c=0;c<col;c++){
				float max= -999999999999999.0;
				float min=  999999999999999.0;
				for (int r=0;r<row;r++){
					if (max < TrainMat->get(r,c))
						max = TrainMat->get(r,c);
					if (min > TrainMat->get(r,c))
						min = TrainMat->get(r,c);
				}
				Range[c]=max-min;
			}

}
//==========

private: System::Void setRangeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			SetRange();
		 }
private: System::Void normBinsearchKnnDivByComplementToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //ED Norm binary search
	int row=TrainMat->Row(),  col=TrainMat->Col();
	twovalues *twovaluesarr; 
	twovaluesarr = new twovalues [row];
	//clac norm of row in data 
	int base;//number of cats
	base =Convert::ToInt16(this->textBox2->Text);
	for (int r=0;r<row;r++){
		float f1=0.0;
		for (int c=0;c<col;c++){
		//	f1+= TrainMat->get(r,c) * TrainMat->get(r,c);
		//	f1+= Math::Pow(2.0,c)*TrainMat->get(r,c);//karp-rabin signiture 2^c* vi
			f1+= Math::Pow(base,c)*TrainMat->get(r,c);
		}
		float complement=Math::Pow(2.0,(float)col)-1.0;
		f1= f1/(complement-f1);
		twovaluesarr[r].v1=f1;
		twovaluesarr[r].v2=r;
	}
	//sor records acording to their norms 	
	qs(twovaluesarr,row);
	twovalues range;
/*	double value= Convert::ToDouble(this->textBox1->Text);
	range = BinarySearch2values(twovaluesarr, row, value);

	this->richTextBox2->AppendText(String::Concat(range.v1.ToString()," - ", range.v2.ToString(), "\n"));
	this->richTextBox2->AppendText(String::Concat(twovaluesarr[(int)range.v1].v1.ToString()," - ", twovaluesarr[(int)range.v2].v1.ToString(), "\n"));
	this->richTextBox2->AppendText(String::Concat(twovaluesarr[(int)range.v1].v2.ToString()," - ", twovaluesarr[(int)range.v2].v2.ToString(), "\n"));
	int k=Convert::ToInt32(this->textBox2->Text);
	range.v1=range.v1-k;
	range.v2=range.v2+k;
	if (range.v1<0){
		range.v2=range.v2+Math::Abs(range.v1);
		range.v1=0;
	}
	if (range.v2>=row){
		range.v1=range.v1-(range.v2-row+1);
		range.v2=row-1;
		if (range.v1<0)
			range.v1=0;	
	}
	this->richTextBox2->AppendText(String::Concat(range.v1.ToString()," }-{ ", range.v2.ToString(), "\n"));
//this need to be out some where 
*/
	float MaxV=-99999999999999999.0;
	for (int r=0;r<row;r++){
		float cl=TrainMat->classint[r];
		if (cl > MaxV)
			MaxV=cl;
	}
			 //knn Norm
			 float sum=0.0;
			 

				int k=Convert::ToInt32(this->textBox2->Text);
				for (int i=0;i<TestMat->Row();i++){
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					//calc norm
					float TestNorm=0.0;
					for (int j=0;j<TestMat->Col();j++){
					//	TestNorm+=testRow[j]*testRow[j];
					//	TestNorm+=Math::Pow(2.0,j)*testRow[j];
						TestNorm+=Math::Pow(base,j)*testRow[j];
					}
					//TestNorm=Math::Sqrt(TestNorm);
					//clac range
					range = BinarySearch2values(twovaluesarr, row, TestNorm);
					range.v1=range.v1-Math::Sqrt(row)/4.0;
					range.v2=range.v2+Math::Sqrt(row)/4.0;
					if (range.v1<0){
						range.v2=range.v2+Math::Abs(range.v1);
						range.v1=0;
					}
					if (range.v2>=row){
						range.v1=range.v1-(range.v2-row+1);
						range.v2=row-1;
						if (range.v1<0)
							range.v1=0;	
					}


					int cs=knnNorm(TrainMat,testRow,k,twovaluesarr,range,MaxV);
					this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					delete []testRow; testRow=0;
				}
			sum=sum/TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("KNN Norm/comp: ",sum.ToString());


delete []twovaluesarr; twovaluesarr=0;
		 }
private: System::Void kNNWithBaggingToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 int r,c,cls;
			 c=TrainMat->Col();
			 r=TrainMat->Row();
			 cls=TrainMat->NumberOfClasses();
			 int bagsize=100;
			 int *classCounters=new int[cls];
			 for (int i=0;i<bagsize;i++){
				 int a=1;
				 int ccount=TrainMat->RowCountOfaClass(i);
				 while((a*ccount/(float) r)<1){a++;}
				 classCounters[i]=TrainMat->RowCountOfaClass(i);
			 }
			 int rr,cc;
			 
			 Mat ** MatBag= new Mat*[bagsize];
			 for (int i=0;i<bagsize;i++){
				 MatBag[i]=new Mat(r,c);
				// MatBag[i]->


			 }
			 for (int i=0;i<bagsize;i++)
				 delete [] MatBag[i];
			 delete  MatBag; MatBag=0;
			 delete [] classCounters; classCounters=0;

		
		 }
private: System::Void kmeanToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
//KMEAN CLUSTERING
     int dim=TrainMat->Col();
	int num_points=TrainMat->Row();
	int k=TrainMat->NumberOfClasses();
	bool class0found=false;
	for (int i=0;i<row;i++){
		if (TrainMat->classint[i]==0){
			class0found=true;
			i=row;
			break;
		}
	}

	if (!class0found)
		k--;
	int x,y,i;
	float  **data_points;
	//initialize
	data_points = new float*[num_points]; //  create arrays of pointers to arrays numRow 
	for( i = 0; i < num_points; i++){
		data_points[i] = new float[dim]; // numCol is defined somewhere 
		}
	//fill in data 
	for (int r=0;r<TrainMat->Row();r++) 
		for (int c = 0; c < TrainMat->Col() ;c++) {
			data_points[r][c]=TrainMat->get(r,c);
		}

   // ScaleFrom0To(data_points,num_points, dim,1.0);
    int *c;
	//cluster data
	c = k_means(data_points, num_points, dim, k, 1e-5, 0);
	if (!class0found)
		for (int r=0;r<TrainMat->Row();r++)
			c[r]++;

	//test clustered data
			 float sum=0;
				for (int i=0;i<TrainMat->Row();i++){
					this->richTextBox5->AppendText(String::Concat(c[i].ToString(),"\n"));
					if (TrainMat->classint[i]==c[i])
						sum++;
				}
			sum=sum/(float) TrainMat->Row();
			label8->Text=String::Concat("K-mean clustering: ",sum.ToString());
//free memeory
   delete [] c; c=0;
	for( i = 0; i < num_points; i++){
		delete [] data_points[i];
		}
		delete data_points; data_points=0;

		 }
private: System::Void kmeanHasDistToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
//KMEAN CLUSTERING with hassanat distance
     int dim=TrainMat->Col();
	int num_points=TrainMat->Row();
	int k=TrainMat->NumberOfClasses();
	bool class0found=false;
	for (int i=0;i<row;i++){
		if (TrainMat->classint[i]==0){
			class0found=true;
			i=row;
			break;
		}
	}

	if (!class0found)
		k--;
	int x,y,i;
	float  **data_points;
	//initialize
	data_points = new float*[num_points]; //  create arrays of pointers to arrays numRow 
	for( i = 0; i < num_points; i++){
		data_points[i] = new float[dim]; // numCol is defined somewhere 
		}
	//fill in data 
	for (int r=0;r<TrainMat->Row();r++) 
		for (int c = 0; c < TrainMat->Col() ;c++) {
			data_points[r][c]=TrainMat->get(r,c);
		}

   // ScaleFrom0To(data_points,num_points, dim,1.0);
    int *c;
	//cluster data
	c = k_meansHas(data_points, num_points, dim, k, 1e-5, 0);
	if (!class0found)
		for (int r=0;r<TrainMat->Row();r++)
			c[r]++;

	//test clustered data
			 float sum=0;
				for (int i=0;i<TrainMat->Row();i++){
					this->richTextBox5->AppendText(String::Concat(c[i].ToString(),"\n"));
					if (TrainMat->classint[i]==c[i])
						sum++;
				}
			sum=sum/(float) TrainMat->Row();
			label8->Text=String::Concat("K-mean clustering: ",sum.ToString());
//free memeory
   delete [] c; c=0;
	for( i = 0; i < num_points; i++){
		delete [] data_points[i];
		}
		delete data_points; data_points=0;

		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 				 this->richTextBox3->Clear();

		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 				 this->richTextBox5->Clear();

		 }
void EOK(int e){
	if (e%10==1){
	//	cout<<"stop";
		this->richTextBox1->AppendText("Stop");
	}
	else{
		
	//	cout<<e<<endl;
		EOK(e/10);
		this->richTextBox1->AppendText(e.ToString()+"\n");
	}
}

private: System::Void testToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	EOK(1234);
		 }
private: System::Void noiseToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 float r = Convert::ToInt32(textBox4->Text)/100; 
			 TrainMat->Noise(r);
		 }
Tree *tree;//01norm tree
Tree2RndPnts *tree2rndp;
Tree2MnMxNorms * tree2MnMxNorms;
//tree 4
Tree2PclosesttoExtreme *tree2ExtremePts;
//tree 5
Tree2FurthestPoints *tree2furthestPts;
//FP decision tree 
DT2FurthestPoints *dt2furthestPts;
DTRandPMinMaxClass *dt2RandPMinMaxCls;
//multi trees
Tree **Multi01NormTree;//01norm tree
int TreesNum;

void printtreestats(){
long n=TrainMat->Row();
	this->richTextBox2->AppendText("\n--Norm Tree Stats--\n"); 
	this->richTextBox2->AppendText("Number of all nodes: " + tree->NumberofNodes.ToString()+"\n");
	this->richTextBox2->AppendText("sum of all examples in all nodes: " + tree->sumsizeofAllnodes.ToString()+"\n");
	this->richTextBox2->AppendText("Number of Leaves: " + tree->NumberofLeaves.ToString()+"\n");
	this->richTextBox2->AppendText("maxDepth: " + tree->maxDepth.ToString()+"\n");
	this->richTextBox2->AppendText("sum of ex in all Leaves: " + tree->sumsizeofLeaves.ToString()+"\n");
	this->richTextBox2->AppendText("num ex in training set : " + n.ToString()+"\n");
	this->richTextBox2->AppendText("min numebr of ex in a Leaf: " + tree->minsizeofLeaf.ToString()+"\n");
	this->richTextBox2->AppendText("max numebr of ex in a Leaf: " + tree->maxsizeofLeaf.ToString()+"\n");
	this->richTextBox2->AppendText("avrg of ex in all Leaves: " + tree->AvrgsizeofLeaves.ToString()+"\n");
	this->richTextBox2->AppendText("Log # of all examples : " + Math::Log(n,2.0).ToString()+"\n");
	this->richTextBox2->AppendText("SQRT # of all examples: " + Math::Sqrt(n).ToString()+"\n");

	this->richTextBox2->AppendText("-- End of Tree Stats--\n");
}
void printtreestats(Tree *tr, long n){
//long n=TrainMat->Row();
	this->richTextBox2->AppendText("\n--Norm Tree Stats--\n"); 
	this->richTextBox2->AppendText("Number of all nodes: " + tr->NumberofNodes.ToString()+"\n");
	this->richTextBox2->AppendText("sum of all examples in all nodes: " + tr->sumsizeofAllnodes.ToString()+"\n");
	this->richTextBox2->AppendText("Number of Leaves: " + tr->NumberofLeaves.ToString()+"\n");
	this->richTextBox2->AppendText("maxDepth: " + tr->maxDepth.ToString()+"\n");
	this->richTextBox2->AppendText("sum of ex in all Leaves: " + tr->sumsizeofLeaves.ToString()+"\n");
	
	this->richTextBox2->AppendText("num ex in training set : " + n.ToString()+"\n");
	this->richTextBox2->AppendText("min numebr of ex in a Leaf: " + tr->minsizeofLeaf.ToString()+"\n");
	this->richTextBox2->AppendText("max numebr of ex in a Leaf: " + tr->maxsizeofLeaf.ToString()+"\n");
	this->richTextBox2->AppendText("avrg of ex in all Leaves: " + tr->AvrgsizeofLeaves.ToString()+"\n");
	this->richTextBox2->AppendText("Log # of all examples : " + Math::Log(n,2.0).ToString()+"\n");
	this->richTextBox2->AppendText("SQRT # of all examples: " + Math::Sqrt(n).ToString()+"\n");

	this->richTextBox2->AppendText("-- End of Tree Stats--\n");
}
void PrintStatTree2FurthestPoints(){ 
long n=TrainMat->Row();
	this->richTextBox2->AppendText("\n--2furthest poipnts Points-Tree Stats--\n"); 
	this->richTextBox2->AppendText("Number of all nodes: " + tree2furthestPts->NumberofNodes.ToString()+"\n");
	this->richTextBox2->AppendText("sum of all examples in all nodes: " + tree2furthestPts->sumsizeofAllnodes.ToString()+"\n");
	this->richTextBox2->AppendText("Number of Leaves: " + tree2furthestPts->NumberofLeaves.ToString()+"\n");
	this->richTextBox2->AppendText("maxDepth: " + tree2furthestPts->maxDepth.ToString()+"\n");
	this->richTextBox2->AppendText("sum of ex in all Leaves: " + tree2furthestPts->sumsizeofLeaves.ToString()+"\n");
	this->richTextBox2->AppendText("num ex in training set : " + n.ToString()+"\n");
	this->richTextBox2->AppendText("min numebr of ex in a Leaf: " + tree2furthestPts->minsizeofLeaf.ToString()+"\n");
	this->richTextBox2->AppendText("max numebr of ex in a Leaf: " + tree2furthestPts->maxsizeofLeaf.ToString()+"\n");
	this->richTextBox2->AppendText("avrg of ex in all Leaves: " + tree2furthestPts->AvrgsizeofLeaves.ToString()+"\n");
	this->richTextBox2->AppendText("Log # of all examples : " + Math::Log(n,2.0).ToString()+"\n");
	this->richTextBox2->AppendText("SQRT # of all examples: " + Math::Sqrt(n).ToString()+"\n");

	this->richTextBox2->AppendText("-- End of Tree Stats--\n");
}

void Printdt2RandPMinMaxCls() {
	long n = TrainMat->Row();
	this->richTextBox1->AppendText("\n--2 random poipnts of min max classes- Decision Tree Stats--\n");
	this->richTextBox1->AppendText("Number of all nodes: " + dt2RandPMinMaxCls->NumberofNodes.ToString() + "\n");
	this->richTextBox1->AppendText("sum of all examples in all nodes: " + dt2RandPMinMaxCls->sumsizeofAllnodes.ToString() + "\n");
	this->richTextBox1->AppendText("Number of Leaves: " + dt2RandPMinMaxCls->NumberofLeaves.ToString() + "\n");
	this->richTextBox1->AppendText("maxDepth: " + dt2RandPMinMaxCls->maxDepth.ToString() + "\n");
	this->richTextBox1->AppendText("sum of ex in all Leaves: " + dt2RandPMinMaxCls->sumsizeofLeaves.ToString() + "\n");
	this->richTextBox1->AppendText("num ex in training set : " + n.ToString() + "\n");
	this->richTextBox1->AppendText("min numebr of ex in a Leaf: " + dt2RandPMinMaxCls->minsizeofLeaf.ToString() + "\n");
	this->richTextBox1->AppendText("max numebr of ex in a Leaf: " + dt2RandPMinMaxCls->maxsizeofLeaf.ToString() + "\n");
	this->richTextBox1->AppendText("avrg of ex in all Leaves: " + dt2RandPMinMaxCls->AvrgsizeofLeaves.ToString() + "\n");
	this->richTextBox1->AppendText("Log # of all examples : " + Math::Log(n, 2.0).ToString() + "\n");
	this->richTextBox1->AppendText("SQRT # of all examples: " + Math::Sqrt(n).ToString() + "\n");

	this->richTextBox1->AppendText("-- End of DTree min max class Stats--\n");
}
void PrintStatDT2furthestPts(){ 
long n=TrainMat->Row();
	this->richTextBox1->AppendText("\n--2furthest poipnts Points- Decision Tree Stats--\n"); 
	this->richTextBox1->AppendText("Number of all nodes: " + dt2furthestPts->NumberofNodes.ToString()+"\n");
	this->richTextBox1->AppendText("sum of all examples in all nodes: " + dt2furthestPts->sumsizeofAllnodes.ToString()+"\n");
	this->richTextBox1->AppendText("Number of Leaves: " + dt2furthestPts->NumberofLeaves.ToString()+"\n");
	this->richTextBox1->AppendText("maxDepth: " + dt2furthestPts->maxDepth.ToString()+"\n");
	this->richTextBox1->AppendText("sum of ex in all Leaves: " + dt2furthestPts->sumsizeofLeaves.ToString()+"\n");
	this->richTextBox1->AppendText("num ex in training set : " + n.ToString()+"\n");
	this->richTextBox1->AppendText("min numebr of ex in a Leaf: " + dt2furthestPts->minsizeofLeaf.ToString()+"\n");
	this->richTextBox1->AppendText("max numebr of ex in a Leaf: " + dt2furthestPts->maxsizeofLeaf.ToString()+"\n");
	this->richTextBox1->AppendText("avrg of ex in all Leaves: " + dt2furthestPts->AvrgsizeofLeaves.ToString()+"\n");
	this->richTextBox1->AppendText("Log # of all examples : " + Math::Log(n,2.0).ToString()+"\n");
	this->richTextBox1->AppendText("SQRT # of all examples: " + Math::Sqrt(n).ToString()+"\n");

	this->richTextBox1->AppendText("-- End of DTree Stats--\n");
}
void PrintStat2ExtrmPntsTree(){ 
long n=TrainMat->Row();
	this->richTextBox2->AppendText("\n--2Extreme Points-Tree Stats--\n"); 
	this->richTextBox2->AppendText("Number of all nodes: " + tree2ExtremePts->NumberofNodes.ToString()+"\n");
	this->richTextBox2->AppendText("sum of all examples in all nodes: " + tree2ExtremePts->sumsizeofAllnodes.ToString()+"\n");
	this->richTextBox2->AppendText("Number of Leaves: " + tree2ExtremePts->NumberofLeaves.ToString()+"\n");
	this->richTextBox2->AppendText("maxDepth: " + tree2ExtremePts->maxDepth.ToString()+"\n");
	this->richTextBox2->AppendText("sum of ex in all Leaves: " + tree2ExtremePts->sumsizeofLeaves.ToString()+"\n");
	this->richTextBox2->AppendText("num ex in training set : " + n.ToString()+"\n");
	this->richTextBox2->AppendText("min numebr of ex in a Leaf: " + tree2ExtremePts->minsizeofLeaf.ToString()+"\n");
	this->richTextBox2->AppendText("max numebr of ex in a Leaf: " + tree2ExtremePts->maxsizeofLeaf.ToString()+"\n");
	this->richTextBox2->AppendText("avrg of ex in all Leaves: " + tree2ExtremePts->AvrgsizeofLeaves.ToString()+"\n");
	this->richTextBox2->AppendText("Log # of all examples : " + Math::Log(n,2.0).ToString()+"\n");
	this->richTextBox2->AppendText("SQRT # of all examples: " + Math::Sqrt(n).ToString()+"\n");

	this->richTextBox2->AppendText("-- End of Tree Stats--\n");
}
void printtreestats2rndpnt(){ 
long n=TrainMat->Row();
	this->richTextBox2->AppendText("\n--2rnd-Tree Stats--\n"); 
	this->richTextBox2->AppendText("Number of all nodes: " + tree2rndp->NumberofNodes.ToString()+"\n");
	this->richTextBox2->AppendText("sum of all examples in all nodes: " + tree2rndp->sumsizeofAllnodes.ToString()+"\n");
	this->richTextBox2->AppendText("Number of Leaves: " + tree2rndp->NumberofLeaves.ToString()+"\n");
	this->richTextBox2->AppendText("maxDepth: " + tree2rndp->maxDepth.ToString()+"\n");
	this->richTextBox2->AppendText("sum of ex in all Leaves: " + tree2rndp->sumsizeofLeaves.ToString()+"\n");
	this->richTextBox2->AppendText("num ex in training set : " + n.ToString()+"\n");
	this->richTextBox2->AppendText("min numebr of ex in a Leaf: " + tree2rndp->minsizeofLeaf.ToString()+"\n");
	this->richTextBox2->AppendText("max numebr of ex in a Leaf: " + tree2rndp->maxsizeofLeaf.ToString()+"\n");
	this->richTextBox2->AppendText("avrg of ex in all Leaves: " + tree2rndp->AvrgsizeofLeaves.ToString()+"\n");
	this->richTextBox2->AppendText("Log # of all examples : " + Math::Log(n,2.0).ToString()+"\n");
	this->richTextBox2->AppendText("SQRT # of all examples: " + Math::Sqrt(n).ToString()+"\n");

	this->richTextBox2->AppendText("-- End of Tree Stats--\n");
}
void printtreestats2MinMaxpnt(){ 
long n=TrainMat->Row();
	this->richTextBox2->AppendText("\n--2pnts of min-max norms-Tree Stats--\n"); 
	this->richTextBox2->AppendText("Number of all nodes: " + tree2MnMxNorms->NumberofNodes.ToString()+"\n");
	this->richTextBox2->AppendText("sum of all examples in all nodes: " + tree2MnMxNorms->sumsizeofAllnodes.ToString()+"\n");
	this->richTextBox2->AppendText("Number of Leaves: " + tree2MnMxNorms->NumberofLeaves.ToString()+"\n");
	this->richTextBox2->AppendText("maxDepth: " + tree2MnMxNorms->maxDepth.ToString()+"\n");
	this->richTextBox2->AppendText("sum of ex in all Leaves: " + tree2MnMxNorms->sumsizeofLeaves.ToString()+"\n");
	this->richTextBox2->AppendText("num ex in training set : " + n.ToString()+"\n");
	this->richTextBox2->AppendText("min numebr of ex in a Leaf: " + tree2MnMxNorms->minsizeofLeaf.ToString()+"\n");
	this->richTextBox2->AppendText("max numebr of ex in a Leaf: " + tree2MnMxNorms->maxsizeofLeaf.ToString()+"\n");
	this->richTextBox2->AppendText("avrg of ex in all Leaves: " + tree2MnMxNorms->AvrgsizeofLeaves.ToString()+"\n");
	this->richTextBox2->AppendText("Log # of all examples : " + Math::Log(n,2.0).ToString()+"\n");
	this->richTextBox2->AppendText("SQRT # of all examples: " + Math::Sqrt(n).ToString()+"\n");

	this->richTextBox2->AppendText("-- End of Tree Stats--\n");
}
private: System::Void train01NormsBtreeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
//this method train a binary search tree where each node store a number of training examples 
//based on their norm similarity, the norms are scaled to 0 and 1 each time, 
//the zero normas examples are stored to the left node 
//and the 1 norms examples are stored to the right, 
//these norms are kept min-max scaled and  classfied to 0,1 
//until they become of the same norm, stored on a leaf node.
//searching this tree is very fast (log n) and will increase the KNN speed 
			 if (tree){
				 delete tree; tree=0;
			 }
			int k=Convert::ToInt32(this->textBox2->Text);
			long n=TrainMat->Row();
			TrainMat->UpdateNorms(DistanceType);
			float *norms=new float[n];
			for (long i=0;i<n;i++)
				norms[i]=TrainMat->Norms[i];
			Stopwatch ^timer = gcnew Stopwatch();  timer->Start(); 
			tree=new Tree(norms,n);
			timer->Stop();
			String ^str11=GlobalfName->Substring(GlobalfName->LastIndexOf("\\")+1);
			this->richTextBox2->AppendText(String::Concat("\n", str11,"\ttime Elapsed to build Bin tree\t", timer->ElapsedMilliseconds.ToString(),"\t"));

			label8->Text=String::Concat("Binary tree of 01 norms has been created : ","\t");
			if (this->checkBox3->Checked)
				tree->TraversBreadth();//this print the tree on a text file DrawTree.txt*/
			printtreestats(); 
			//delete tree; tree=0;
			//print tree stats
				
			delete [] norms;
		 }
private: System::Void test01NormsBtreeNNToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//this search for all examples in the test set in the created binary tree until 
	//reaching a leafe node 
			 TestMat->UpdateNorms(DistanceType);
			 float MaxV=-99999999999999999.0;
			for (long rr=0;rr<TrainMat->Row();rr++){
				float cl=TrainMat->classint[rr];
				if (cl > MaxV)
					MaxV=cl;
			}
			 float sum=0;
			 long *classinttwo=new long[TestMat->Row()];
			 long *classinttoo=new long[TestMat->Row()];
			 long * FN=new long[TestMat->NumberOfClasses()];
			 long * FP=new long[TestMat->NumberOfClasses()];
			 long * TN=new long[TestMat->NumberOfClasses()];
			 float * precision=new float[TestMat->NumberOfClasses()];
			 float * Recall=new float[TestMat->NumberOfClasses()];
             ArrayList^n=gcnew ArrayList();
		    long** classmat = new long*[TestMat->NumberOfClasses()];
            for(long i = 0; i < TestMat->NumberOfClasses(); ++i)
            classmat[i] = new long[TestMat->NumberOfClasses()];
			 for (long i=0;i<TestMat->Row();i++)
				{
					if ( ! n->Contains(TestMat->classint[i]))
						n->Add(TestMat->classint[i]);
			    }
				//classification	
				int k=Convert::ToInt32(this->textBox2->Text);
				this->progressBar1->Maximum=TestMat->Row();this->progressBar1->Value=0;
				Stopwatch ^timer = gcnew Stopwatch();  timer->Start();  
				for (long i=0;i<TestMat->Row();i++){
					//get the first test example 
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					//get the training indexes from the tree 
					BTreeNode * temp=tree->GetExamples(TestMat->Norms[i]);
					long cs=knnBtree(TrainMat,testRow,k,temp, MaxV);
					if (this->checkBox3->Checked)
						this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					classinttwo[i]=cs;
					classinttoo[i]=TestMat->classint[i];
					delete []testRow; testRow=0;
					this->progressBar1->Value++; Application::DoEvents();
				}
				//end classification
				timer->Stop();
			String ^str11=GlobalfName->Substring(GlobalfName->LastIndexOf("\\")+1);
				
				this->richTextBox2->AppendText(String::Concat("\n",str11,"\ttime Elapsed KNN tree\t", timer->ElapsedMilliseconds.ToString(),"\n"));

				long index1=0;
				long index2=0;
				for (long i=0;i<TestMat->NumberOfClasses();i++)
					for (long j=0;j<TestMat->NumberOfClasses();j++)
						classmat[i][j]=0;

                //confusion matrix 
				for (long i=0;i<TestMat->Row();i++){
				    index1=n->IndexOf(classinttoo[i]);
					index2=n->IndexOf(classinttwo[i]);  
					if(classinttoo[i]== classinttwo[i])
						classmat[index1][index1]+=1;
					else
						classmat[index1][index2]+=1;

				}
                   
                delete []classinttoo;
                delete []classinttwo;


				int sumTP = 0;
            	for (int i=0;i<TestMat->NumberOfClasses();i++)
				{
					FN[i]=0;
					FP[i]=0;
					TN[i]=0;
					precision[i]=0.0;
					Recall[i]=0.0;
				}


            for (int i=0;i<TestMat->NumberOfClasses();i++)
					for (int j=0;j<TestMat->NumberOfClasses();j++)
						if(j!=i)
							FP[i]+=classmat[i][j];

			for (int i=0;i<TestMat->NumberOfClasses();i++)
					for (int j=0;j<TestMat->NumberOfClasses();j++)
						if(j!=i)
                  FN[i]+=classmat[j][i];

			 for (int i=0;i<TestMat->NumberOfClasses();i++)					
                 sumTP+=classmat[i][i];
             
			 for (int k=0;k<TestMat->NumberOfClasses();k++)
						
                  TN[k]=sumTP-classmat[k][k];

             for (int m=0;m<TestMat->NumberOfClasses();m++)
				if(	classmat[m][m]+ FP[m] == 0)
                    precision[m]=0.0;
				else
					precision[m]=classmat[m][m]/(float)(classmat[m][m]+FP[m]);

			 for (int v=0;v<TestMat->NumberOfClasses();v++)
				if(classmat[v][v]+FN[v] == 0)
                   Recall[v]=0.0;
				else
                   Recall[v]=classmat[v][v]/(float)(classmat[v][v]+FN[v]);
                
              float AvgPrecision = 0.0;
			  float SumPrecision = 0.0;
			  float SumRecall = 0.0;
              float AvgRecall = 0.0;
              for (int z=0;z<TestMat->NumberOfClasses();z++)
			  {
				  SumPrecision+=precision[z];
				  SumRecall+=Recall[z];
			  }


                delete []TN;
                delete []FN;
				delete []FP;
                delete [] Recall;
				delete [] precision;
				for(int i = 0; i < TestMat->NumberOfClasses(); ++i) {
                   delete [] classmat[i];
                }
                delete [] classmat;
           
            AvgRecall=SumRecall/(float)TestMat->NumberOfClasses();
            AvgPrecision=SumPrecision/(float)TestMat->NumberOfClasses();
			AvgRecall=Math::Round(AvgRecall,4.0);
			AvgPrecision=Math::Round(AvgPrecision,4.0);


			sum=sum/(float) TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat(" Norm tree Accuarcy\t",sum.ToString(),"\tRecall\t",AvgRecall.ToString(),"\tPrecision\t",AvgPrecision.ToString());
			this->richTextBox2->AppendText("k= " + this->textBox2->Text + label8->Text);

		 }
private: System::Void test01NormsBtreeWithLognExamplesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
//this test binary tree using at least log n examples,insted of going deep to the leafe,
//where the searched example might not be there, but by taking more examples from a 
//parent node, the approximate nearest example is more likely to be found, 
//this is due to the similarity in the norm of examples of different classes.

			 TestMat->UpdateNorms(DistanceType);//creat norms for each test example
			 float MaxV=-99999999999999999.0;
			for (long rr=0;rr<TrainMat->Row();rr++){
				float cl=TrainMat->classint[rr];
				if (cl > MaxV)
					MaxV=cl;
			}

			 float sum=0;
			 long *classinttwo=new long[TestMat->Row()];
			 long *classinttoo=new long[TestMat->Row()];
			 long * FN=new long[TestMat->NumberOfClasses()];
			 long * FP=new long[TestMat->NumberOfClasses()];
			 long * TN=new long[TestMat->NumberOfClasses()];
			 float * precision=new float[TestMat->NumberOfClasses()];
			 float * Recall=new float[TestMat->NumberOfClasses()];
             ArrayList^n=gcnew ArrayList();
		    long** classmat = new long*[TestMat->NumberOfClasses()];
            for(long i = 0; i < TestMat->NumberOfClasses(); ++i)
            classmat[i] = new long[TestMat->NumberOfClasses()];
			 for (long i=0;i<TestMat->Row();i++)
				{
					if ( ! n->Contains(TestMat->classint[i]))
						n->Add(TestMat->classint[i]);
			    }
				//classification	
				int k=Convert::ToInt32(this->textBox2->Text);
				this->progressBar1->Maximum=TestMat->Row();this->progressBar1->Value=0;
				Stopwatch ^timer = gcnew Stopwatch();  timer->Start(); 
				long LognumTrainexamples = Math::Round(Math::Log(TrainMat->Row(),2));//log num examples in training set
				float scalelog=Convert::ToDouble(this->textBox4->Text);
				LognumTrainexamples=LognumTrainexamples * scalelog;
				float SumReturnedExamples=0.0;
				for (long i=0;i<TestMat->Row();i++){
					//get the first test example 
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					//get the training indexes from the tree 
					BTreeNode * temp=tree->GetExamples(TestMat->Norms[i], LognumTrainexamples);
					SumReturnedExamples+=temp->size;
					long cs=knnBtree(TrainMat,testRow,k,temp, MaxV);
					if (this->checkBox3->Checked)
						this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					classinttwo[i]=cs;
					classinttoo[i]=TestMat->classint[i];
					delete []testRow; testRow=0;
					this->progressBar1->Value++; Application::DoEvents();
				}
				//end classification
				timer->Stop();
			String ^str11=GlobalfName->Substring(GlobalfName->LastIndexOf("\\")+1);
				this->richTextBox2->AppendText(String::Concat("\n",str11,"\ttime Elapsed KNN tree\t", timer->ElapsedMilliseconds.ToString(),"\n"));
				SumReturnedExamples=SumReturnedExamples/TestMat->Row();
				this->richTextBox2->AppendText(String::Concat("\nAverage of returned examples= ", SumReturnedExamples.ToString(),"\n"));

				long index1=0;
				long index2=0;
				for (long i=0;i<TestMat->NumberOfClasses();i++)
					for (long j=0;j<TestMat->NumberOfClasses();j++)
						classmat[i][j]=0;

                //confusion matrix 
				for (long i=0;i<TestMat->Row();i++){
				    index1=n->IndexOf(classinttoo[i]);
					index2=n->IndexOf(classinttwo[i]);  
					if(classinttoo[i]== classinttwo[i])
						classmat[index1][index1]+=1;
					else
						classmat[index1][index2]+=1;

				}
                   
                delete []classinttoo;
                delete []classinttwo;


				int sumTP = 0;
            	for (int i=0;i<TestMat->NumberOfClasses();i++)
				{
					FN[i]=0;
					FP[i]=0;
					TN[i]=0;
					precision[i]=0.0;
					Recall[i]=0.0;
				}


            for (int i=0;i<TestMat->NumberOfClasses();i++)
					for (int j=0;j<TestMat->NumberOfClasses();j++)
						if(j!=i)
							FP[i]+=classmat[i][j];

			for (int i=0;i<TestMat->NumberOfClasses();i++)
					for (int j=0;j<TestMat->NumberOfClasses();j++)
						if(j!=i)
                  FN[i]+=classmat[j][i];

			 for (int i=0;i<TestMat->NumberOfClasses();i++)					
                 sumTP+=classmat[i][i];
             
			 for (int k=0;k<TestMat->NumberOfClasses();k++)
						
                  TN[k]=sumTP-classmat[k][k];

             for (int m=0;m<TestMat->NumberOfClasses();m++)
				if(	classmat[m][m]+ FP[m] == 0)
                    precision[m]=0.0;
				else
					precision[m]=classmat[m][m]/(float)(classmat[m][m]+FP[m]);

			 for (int v=0;v<TestMat->NumberOfClasses();v++)
				if(classmat[v][v]+FN[v] == 0)
                   Recall[v]=0.0;
				else
                   Recall[v]=classmat[v][v]/(float)(classmat[v][v]+FN[v]);
                
              float AvgPrecision = 0.0;
			  float SumPrecision = 0.0;
			  float SumRecall = 0.0;
              float AvgRecall = 0.0;
              for (int z=0;z<TestMat->NumberOfClasses();z++)
			  {
				  SumPrecision+=precision[z];
				  SumRecall+=Recall[z];
			  }


                delete []TN;
                delete []FN;
				delete []FP;
                delete [] Recall;
				delete [] precision;
				for(int i = 0; i < TestMat->NumberOfClasses(); ++i) {
                   delete [] classmat[i];
                }
                delete [] classmat;
           
            AvgRecall=SumRecall/(float)TestMat->NumberOfClasses();
            AvgPrecision=SumPrecision/(float)TestMat->NumberOfClasses();
			AvgRecall=Math::Round(AvgRecall,4.0);
			AvgPrecision=Math::Round(AvgPrecision,4.0);


			sum=sum/(float) TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat(" KNN Result: ",sum.ToString(),"  Recall :",AvgRecall.ToString(),"  Precision:",AvgPrecision.ToString());
			this->richTextBox2->AppendText("k= " + this->textBox2->Text + label8->Text);

		 }
private: System::Void bFFarthestDistanceToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				
				long ip1,ip2,iterations=0;
				float D;
				Stopwatch ^timer; /*= gcnew Stopwatch();  timer->Start(); 
				D=bruteForceFar(TrainMat, &ip1,&ip2);
				timer->Stop();
				this->richTextBox2->AppendText(String::Concat("\ntime Elapsed KNN tree:", timer->ElapsedMilliseconds.ToString(),"\n"));
				this->richTextBox2->AppendText(String::Concat("\nFarthest distance=",D.ToString()," Between point ",ip1.ToString(), " And ", ip2.ToString(),"\n"));
				*/
//if we got indexes of examples

				long n=TrainMat->Row();
				long *fvindex=new long[n];
				for (long i=0;i<n;i++)
					fvindex[i]=i;
				timer = gcnew Stopwatch();  timer->Start();	
				iterations=0;
				D=bruteForceFar(TrainMat,fvindex, n, &ip1,&ip2, &iterations);
				timer->Stop();
				String ^str11=GlobalfName->Substring(GlobalfName->LastIndexOf("\\")+1);
				this->richTextBox2->AppendText(String::Concat(str11,"\nBrute force\tTime\t", timer->ElapsedMilliseconds.ToString(),"\t"));
				this->richTextBox2->AppendText(String::Concat("Farthest distance\t",D.ToString(),"\tpoint1\t",ip1.ToString(), "\tpoint2\t", ip2.ToString(), "\tIterations\t", iterations.ToString(),"\n"));
				TrainMat->setMaxes();
				float * mn=TrainMat->Min;
				float * mx=TrainMat->Max;
				String ^str1=gcnew String("");
				String ^str2=gcnew String("");
			/*	for (int i=0;i<TrainMat->Col();i++){
					str1=str1+TrainMat->Min[i]+" ";
					str2=str2+TrainMat->Max[i]+" ";
				}
				this->richTextBox2->AppendText(String::Concat("\n",str1,"\n",str2, "\n"));
		*/
				timer = gcnew Stopwatch();  timer->Start();	
				TrainMat->setMaxes();
				D=FastFar1(TrainMat,fvindex, n, &ip1,&ip2,&iterations);
				timer->Stop();
				this->richTextBox2->AppendText(String::Concat("AFP 2 ends\tTime\t", timer->ElapsedMilliseconds.ToString(),"\t"));
				this->richTextBox2->AppendText(String::Concat("Farthest distance\t",D.ToString(),"\tpoint1\t",ip1.ToString(), "\tpoint2\t", ip2.ToString(), "\tIterations\t", iterations.ToString(),"\n"));

				timer = gcnew Stopwatch();  timer->Start();	
				//TrainMat->setMaxes();
			//	D=FastFar2(TrainMat,fvindex, n, &ip1,&ip2, &iterations);
				timer->Stop();
				this->richTextBox2->AppendText(String::Concat("AFP 2 ends D1/D2 D2/D1\tTime\t", timer->ElapsedMilliseconds.ToString(),"\t"));
				this->richTextBox2->AppendText(String::Concat("Farthest distance\t",D.ToString(),"\tpoint1\t",ip1.ToString(), "\tpoint2\t", ip2.ToString(), "\tIterations\t", iterations.ToString(),"\n"));
//third method: FastFar3 
				timer = gcnew Stopwatch();  timer->Start();	
				//TrainMat->setMaxes();
		//		D=FastFar3(TrainMat,fvindex, n, &ip1,&ip2,&iterations);
				timer->Stop();
				this->richTextBox2->AppendText(String::Concat("AFP 2 ends D1/D2 D2/D1 multi points\tTime\t", timer->ElapsedMilliseconds.ToString(),"\t"));
				this->richTextBox2->AppendText(String::Concat("Farthest distance\t",D.ToString(),"\tpoint1\t",ip1.ToString(), "\tpoint2\t", ip2.ToString(), "\tIterations\t", iterations.ToString(),"\n"));
//4th method: FastFar4 
				
				timer = gcnew Stopwatch();  timer->Start();	
				TrainMat->UpdateNorms();
				D=FastFar4(TrainMat,fvindex, n, &ip1,&ip2,&iterations);
				timer->Stop();
				this->richTextBox2->AppendText(String::Concat("min,max norms\tTime\t", timer->ElapsedMilliseconds.ToString(),"\t"));
				this->richTextBox2->AppendText(String::Concat("Farthest distance\t",D.ToString(),"\tpoint1\t",ip1.ToString(), "\tpoint2\t", ip2.ToString(), "\tIterations\t", iterations.ToString(),"\n"));
//4th method: FastFar4 
				
				timer = gcnew Stopwatch();  timer->Start();	
				TrainMat->UpdateShiftedNorms();
				D=FastFar8(TrainMat,fvindex, n, &ip1,&ip2,&iterations);
				timer->Stop();
				this->richTextBox2->AppendText(String::Concat("min,max shifted norms\tTime\t", timer->ElapsedMilliseconds.ToString(),"\t"));
				this->richTextBox2->AppendText(String::Concat("Farthest distance\t",D.ToString(),"\tpoint1\t",ip1.ToString(), "\tpoint2\t", ip2.ToString(), "\tIterations\t", iterations.ToString(),"\n"));

//5th method FastFar5
				timer = gcnew Stopwatch();  timer->Start();	
				TrainMat->UpdateNorms();
				D=FastFar5(TrainMat,fvindex, n, &ip1,&ip2,&iterations);
				timer->Stop();
				this->richTextBox2->AppendText(String::Concat("wieght simialirty\tTime\t", timer->ElapsedMilliseconds.ToString(),"\t"));
				this->richTextBox2->AppendText(String::Concat("Farthest distance\t",D.ToString(),"\tpoint1\t",ip1.ToString(), "\tpoint2\t", ip2.ToString(), "\tIterations\t", iterations.ToString(),"\n"));
//6th method FastFar6 Hassanat
				timer = gcnew Stopwatch();  timer->Start();	
				TrainMat->UpdateNorms();
				D=FastFar6(TrainMat,fvindex, n, &ip1,&ip2,&iterations);
				timer->Stop();
				this->richTextBox2->AppendText(String::Concat("Hassanat distance\tTime\t", timer->ElapsedMilliseconds.ToString(),"\t"));
				this->richTextBox2->AppendText(String::Concat("Farthest distance\t",D.ToString(),"\tpoint1\t",ip1.ToString(), "\tpoint2\t", ip2.ToString(), "\tIterations\t", iterations.ToString(),"\n"));
//6th method FastFar6 Hassanat FastFar9
				timer = gcnew Stopwatch();  timer->Start();	
				TrainMat->UpdateNorms();
		//		D=FastFar7(TrainMat,fvindex, n, &ip1,&ip2,&iterations);
				timer->Stop();
				this->richTextBox2->AppendText(String::Concat("weight/Hassanat\tTime\t", timer->ElapsedMilliseconds.ToString(),"\t"));
				this->richTextBox2->AppendText(String::Concat("Farthest distance\t",D.ToString(),"\tpoint1\t",ip1.ToString(), "\tpoint2\t", ip2.ToString(), "\tIterations\t", iterations.ToString(),"\n"));
//9th method FastFar9 wehight/ED FastFar10
				timer = gcnew Stopwatch();  timer->Start();	 
		//		D=FastFar9(TrainMat,fvindex, n, &ip1,&ip2,&iterations);
				timer->Stop();
				this->richTextBox2->AppendText(String::Concat("weight/ED\tTime\t", timer->ElapsedMilliseconds.ToString(),"\t"));
				this->richTextBox2->AppendText(String::Concat("Farthest distance\t",D.ToString(),"\tpoint1\t",ip1.ToString(), "\tpoint2\t", ip2.ToString(), "\tIterations\t", iterations.ToString(),"\n"));
//10th method FastFar10 min, max zones 
				timer = gcnew Stopwatch();  timer->Start();	 
		//		D=FastFar10(TrainMat,fvindex, n, &ip1,&ip2,&iterations);
				timer->Stop();
				this->richTextBox2->AppendText(String::Concat("Min,Max Zones\tTime\t", timer->ElapsedMilliseconds.ToString(),"\t"));
				this->richTextBox2->AppendText(String::Concat("Farthest distance\t",D.ToString(),"\tpoint1\t",ip1.ToString(), "\tpoint2\t", ip2.ToString(), "\tIterations\t", iterations.ToString(),"\n"));
	/*			float *p1=TrainMat->getRow(ip1);
				float *p2=TrainMat->getRow(ip2);
				str1=gcnew String("");
				str2=gcnew String("");
				for (int i=0;i<TrainMat->Col();i++){
					str1=str1+ p1[i] +" ";
					str2=str2+ p2[i] +" ";
				}
				this->richTextBox2->AppendText(String::Concat("\n",str1,"\n",str2, "\n"));

				delete []p1; delete []p2;*/
//11th method FastFar11 
				timer = gcnew Stopwatch();  timer->Start();	 
		//		D=FastFar11(TrainMat,fvindex, n, &ip1,&ip2,&iterations);
				timer->Stop();
				this->richTextBox2->AppendText(String::Concat("Min,Max Zones with weight sim\tTime\t", timer->ElapsedMilliseconds.ToString(),"\t"));
				this->richTextBox2->AppendText(String::Concat("Farthest distance\t",D.ToString(),"\tpoint1\t",ip1.ToString(), "\tpoint2\t", ip2.ToString(), "\tIterations\t", iterations.ToString(),"\n"));
//12th method  
				timer = gcnew Stopwatch();  timer->Start();	 
		//		D=FastFar12(TrainMat,fvindex, n, &ip1,&ip2, &iterations);
				timer->Stop();
				this->richTextBox2->AppendText(String::Concat("Min,Max Zones weighted ED\tTime\t", timer->ElapsedMilliseconds.ToString(),"\t"));
				this->richTextBox2->AppendText(String::Concat("Farthest distance\t",D.ToString(),"\tpoint1\t",ip1.ToString(), "\tpoint2\t", ip2.ToString(), "\tIterations\t", iterations.ToString(),"\n"));
//13th method hill climbing 
				timer = gcnew Stopwatch();  timer->Start();	 
				//A2 in the paper
				D=FastFar13(TrainMat,fvindex, n, &ip1,&ip2,0);
				timer->Stop();
				this->richTextBox2->AppendText(String::Concat("Hill climbing rnd\tTime\t", timer->ElapsedMilliseconds.ToString(),"\t"));
				this->richTextBox2->AppendText(String::Concat("Farthest distance\t",D.ToString(),"\tpoint1\t",ip1.ToString(), "\tpoint2\t", ip2.ToString(), "\tIterations\t", iterations.ToString(),"\n"));
//14th method hill climbing initial seed max dist from extreme min
				timer = gcnew Stopwatch();  timer->Start();	 
		//		D=FastFar14(TrainMat,fvindex, n, &ip1,&ip2,&iterations);
				timer->Stop();
				this->richTextBox2->AppendText(String::Concat("Hill climbing Extreme\tTime\t", timer->ElapsedMilliseconds.ToString(),"\t"));
				this->richTextBox2->AppendText(String::Concat("Farthest distance\t",D.ToString(),"\tpoint1\t",ip1.ToString(), "\tpoint2\t", ip2.ToString(), "\tIterations\t", iterations.ToString(),"\n"));
//15th method tabu with visited memory
				timer = gcnew Stopwatch();  timer->Start();	 
		//		D=FastFar15(TrainMat,fvindex, n, &ip1,&ip2,&iterations);
				timer->Stop();
				this->richTextBox2->AppendText(String::Concat("Tabu +visited memory\tTime\t", timer->ElapsedMilliseconds.ToString(),"\t"));
				this->richTextBox2->AppendText(String::Concat("Farthest distance\t",D.ToString(),"\tpoint1\t",ip1.ToString(), "\tpoint2\t", ip2.ToString(), "\tIterations\t", iterations.ToString(),"\n"));
//16th method tabu with visited memory
				timer = gcnew Stopwatch();  timer->Start();	 
				D=FastFar16(TrainMat,fvindex, n, &ip1,&ip2,&iterations);
				timer->Stop();
				this->richTextBox2->AppendText(String::Concat("Tabu queue + visited memory\tTime\t", timer->ElapsedMilliseconds.ToString(),"\t"));
				this->richTextBox2->AppendText(String::Concat("Farthest distance\t",D.ToString(),"\tpoint1\t",ip1.ToString(), "\tpoint2\t", ip2.ToString(), "\tIterations\t", iterations.ToString(),"\n"));
//16th method beam search with visited memory
				timer = gcnew Stopwatch();  timer->Start();	 
				D=FastFar17(TrainMat,fvindex, n, &ip1,&ip2,&iterations);
				timer->Stop();
				this->richTextBox2->AppendText(String::Concat("beam search + visited memory\tTime\t", timer->ElapsedMilliseconds.ToString(),"\t"));
				this->richTextBox2->AppendText(String::Concat("Farthest distance\t",D.ToString(),"\tpoint1\t",ip1.ToString(), "\tpoint2\t", ip2.ToString(), "\tIterations\t", iterations.ToString(),"\n"));

//another method
				//build the binary tree 
				//go to the left of the tree and take log n points 
				//go to the right of the tree and take log n points 
				//do bruce forc algorithm to find the maximum distance 
		 }
private: System::Void test01normsBtreeWith2logExamplesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		 }
private: System::Void trainBtreeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
//this method train a binary search tree where each node store a number of training examples 
//based on their similarity to two randmo points from the training data, 
//similar points to p1 are stored to the left node 
//similar points to p1 are stored to the right, 
//the examples are then clustered in a Bsearch tree 
//until they become one point, whch is stored stored in a leaf node.
//searching this tree is very fast (dlog n) and will increase the KNN speed 
			 if (tree2rndp){
				 delete tree2rndp; tree2rndp=0;
			 }
			int k=Convert::ToInt32(this->textBox2->Text);
			long n=TrainMat->Row();
			//TrainMat->UpdateNorms(DistanceType);
			//float *norms=new float[n];
			//for (long i=0;i<n;i++)
				//norms[i]=TrainMat->Norms[i];
			Stopwatch ^timer = gcnew Stopwatch();  timer->Start(); 
			tree2rndp=new Tree2RndPnts(TrainMat,DistanceType);
			timer->Stop();
			String ^str11=GlobalfName->Substring(GlobalfName->LastIndexOf("\\")+1);
			this->richTextBox2->AppendText(String::Concat("\n", str11,"\ttime Elapsed to build 2rnd pnts Bintree\t", timer->ElapsedMilliseconds.ToString(),"\t"));

			label8->Text=String::Concat("Binary tree of 2 Rnd Points is created : ","\t");
			if (this->checkBox3->Checked)
				tree2rndp->TraversBreadth();//this print the tree on a text file DrawTree.txt*/
			printtreestats2rndpnt(); 
			//delete tree; tree=0;
			//print tree stats
				
		 }
private: System::Void testTreeToLeafToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//this search for all examples in the test set in the created 2rnd pnts binary tree until 
	//reaching a leafe node to return, which may/may not contain one example
			// TestMat->UpdateNorms(DistanceType);
			 float MaxV=-99999999999999999.0;
			for (long rr=0;rr<TrainMat->Row();rr++){
				float cl=TrainMat->classint[rr];
				if (cl > MaxV)
					MaxV=cl;
			}
			 float sum=0;
			 long *classinttwo=new long[TestMat->Row()];
			 long *classinttoo=new long[TestMat->Row()];
			 long * FN=new long[TestMat->NumberOfClasses()];
			 long * FP=new long[TestMat->NumberOfClasses()];
			 long * TN=new long[TestMat->NumberOfClasses()];
			 float * precision=new float[TestMat->NumberOfClasses()];
			 float * Recall=new float[TestMat->NumberOfClasses()];
             ArrayList^n=gcnew ArrayList();
		    long** classmat = new long*[TestMat->NumberOfClasses()];
            for(long i = 0; i < TestMat->NumberOfClasses(); ++i)
            classmat[i] = new long[TestMat->NumberOfClasses()];
			 for (long i=0;i<TestMat->Row();i++)
				{
					if ( ! n->Contains(TestMat->classint[i]))
						n->Add(TestMat->classint[i]);
			    }
//classification================================================================
				int k=Convert::ToInt32(this->textBox2->Text);
				this->progressBar1->Maximum=TestMat->Row();this->progressBar1->Value=0;
				Stopwatch ^timer = gcnew Stopwatch();  timer->Start();  
				for (long i=0;i<TestMat->Row();i++){
					//get the first test example 
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					//get the training indexes from the tree 
					BTreeNode * temp=tree2rndp->GetExamples(TrainMat,TestMat, i,DistanceType);
					long cs=knnBtree(TrainMat,testRow,k,temp, MaxV);
					if (this->checkBox3->Checked)
						this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					classinttwo[i]=cs;
					classinttoo[i]=TestMat->classint[i];
					delete []testRow; testRow=0;
					this->progressBar1->Value++; Application::DoEvents();
				}
				timer->Stop();
//end classification=============================================================
			String ^str11=GlobalfName->Substring(GlobalfName->LastIndexOf("\\")+1);
				
				this->richTextBox2->AppendText(String::Concat("\n",str11,"\ttime Elapsed KNN 2rnd-Pts-tree\t", timer->ElapsedMilliseconds.ToString(),"\n"));

				long index1=0;
				long index2=0;
				for (long i=0;i<TestMat->NumberOfClasses();i++)
					for (long j=0;j<TestMat->NumberOfClasses();j++)
						classmat[i][j]=0;

                //confusion matrix 
				for (long i=0;i<TestMat->Row();i++){
				    index1=n->IndexOf(classinttoo[i]);
					index2=n->IndexOf(classinttwo[i]);  
					if(classinttoo[i]== classinttwo[i])
						classmat[index1][index1]+=1;
					else
						classmat[index1][index2]+=1;

				}
                   
                delete []classinttoo;
                delete []classinttwo;


				int sumTP = 0;
            	for (int i=0;i<TestMat->NumberOfClasses();i++)
				{
					FN[i]=0;
					FP[i]=0;
					TN[i]=0;
					precision[i]=0.0;
					Recall[i]=0.0;
				}


            for (int i=0;i<TestMat->NumberOfClasses();i++)
					for (int j=0;j<TestMat->NumberOfClasses();j++)
						if(j!=i)
							FP[i]+=classmat[i][j];

			for (int i=0;i<TestMat->NumberOfClasses();i++)
					for (int j=0;j<TestMat->NumberOfClasses();j++)
						if(j!=i)
                  FN[i]+=classmat[j][i];

			 for (int i=0;i<TestMat->NumberOfClasses();i++)					
                 sumTP+=classmat[i][i];
             
			 for (int k=0;k<TestMat->NumberOfClasses();k++)
						
                  TN[k]=sumTP-classmat[k][k];

             for (int m=0;m<TestMat->NumberOfClasses();m++)
				if(	classmat[m][m]+ FP[m] == 0)
                    precision[m]=0.0;
				else
					precision[m]=classmat[m][m]/(float)(classmat[m][m]+FP[m]);

			 for (int v=0;v<TestMat->NumberOfClasses();v++)
				if(classmat[v][v]+FN[v] == 0)
                   Recall[v]=0.0;
				else
                   Recall[v]=classmat[v][v]/(float)(classmat[v][v]+FN[v]);
                
              float AvgPrecision = 0.0;
			  float SumPrecision = 0.0;
			  float SumRecall = 0.0;
              float AvgRecall = 0.0;
              for (int z=0;z<TestMat->NumberOfClasses();z++)
			  {
				  SumPrecision+=precision[z];
				  SumRecall+=Recall[z];
			  }


                delete []TN;
                delete []FN;
				delete []FP;
                delete [] Recall;
				delete [] precision;
				for(int i = 0; i < TestMat->NumberOfClasses(); ++i) {
                   delete [] classmat[i];
                }
                delete [] classmat;
           
            AvgRecall=SumRecall/(float)TestMat->NumberOfClasses();
            AvgPrecision=SumPrecision/(float)TestMat->NumberOfClasses();
			AvgRecall=Math::Round(AvgRecall,4.0);
			AvgPrecision=Math::Round(AvgPrecision,4.0);


			sum=sum/(float) TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat(" 2rnd-pnts-Btree accuracy\t",sum.ToString(),"\tRecall\t",AvgRecall.ToString(),"\tPrecision:",AvgPrecision.ToString());
			this->richTextBox2->AppendText("k= " + this->textBox2->Text + label8->Text);

		 }
private: System::Void testTreeToKlognToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//this search for all examples in the test set in the created 2rnd pnts binary tree until 
	//reaching a leafe node to return, which may/may not contain one example
			// TestMat->UpdateNorms(DistanceType);
			 float MaxV=-99999999999999999.0;
			for (long rr=0;rr<TrainMat->Row();rr++){
				float cl=TrainMat->classint[rr];
				if (cl > MaxV)
					MaxV=cl;
			}
			 float sum=0;
			 long *classinttwo=new long[TestMat->Row()];
			 long *classinttoo=new long[TestMat->Row()];
			 long * FN=new long[TestMat->NumberOfClasses()];
			 long * FP=new long[TestMat->NumberOfClasses()];
			 long * TN=new long[TestMat->NumberOfClasses()];
			 float * precision=new float[TestMat->NumberOfClasses()];
			 float * Recall=new float[TestMat->NumberOfClasses()];
             ArrayList^n=gcnew ArrayList();
		    long** classmat = new long*[TestMat->NumberOfClasses()];
            for(long i = 0; i < TestMat->NumberOfClasses(); ++i)
            classmat[i] = new long[TestMat->NumberOfClasses()];
			 for (long i=0;i<TestMat->Row();i++)
				{
					if ( ! n->Contains(TestMat->classint[i]))
						n->Add(TestMat->classint[i]);
			    }
//classification================================================================
				int k=Convert::ToInt32(this->textBox2->Text);
				this->progressBar1->Maximum=TestMat->Row();this->progressBar1->Value=0;
				Stopwatch ^timer = gcnew Stopwatch();  timer->Start();  
				long LognumTrainexamples = Math::Round(Math::Log(TrainMat->Row(),2));//log num examples in training set
				float scalelog=Convert::ToDouble(this->textBox4->Text);
				LognumTrainexamples=LognumTrainexamples * scalelog;
				float SumReturnedExamples=0.0;
				
				for (long i=0;i<TestMat->Row();i++){
					//get the first test example 
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					//get the training indexes from the tree 
					BTreeNode * temp=tree2rndp->GetExamples(TrainMat,TestMat, i,DistanceType,LognumTrainexamples);
					long cs=knnBtree(TrainMat,testRow,k,temp, MaxV);
					SumReturnedExamples+=temp->size;
					if (this->checkBox3->Checked)
						this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					classinttwo[i]=cs;
					classinttoo[i]=TestMat->classint[i];
					delete []testRow; testRow=0;
					this->progressBar1->Value++; Application::DoEvents();
				}
				timer->Stop();
//end classification=============================================================
			String ^str11=GlobalfName->Substring(GlobalfName->LastIndexOf("\\")+1);
				
				this->richTextBox2->AppendText(String::Concat("\n",str11,"\ttime Elapsed KNN 2rnd-Pts-tree\t", timer->ElapsedMilliseconds.ToString(),"\n"));

				SumReturnedExamples=SumReturnedExamples/TestMat->Row();
				this->richTextBox2->AppendText(String::Concat("\nAverage of returned examples= ", SumReturnedExamples.ToString(),"\n"));

				long index1=0;
				long index2=0;
				for (long i=0;i<TestMat->NumberOfClasses();i++)
					for (long j=0;j<TestMat->NumberOfClasses();j++)
						classmat[i][j]=0;

                //confusion matrix 
				for (long i=0;i<TestMat->Row();i++){
				    index1=n->IndexOf(classinttoo[i]);
					index2=n->IndexOf(classinttwo[i]);  
					if(classinttoo[i]== classinttwo[i])
						classmat[index1][index1]+=1;
					else
						classmat[index1][index2]+=1;

				}
                   
                delete []classinttoo;
                delete []classinttwo;


				int sumTP = 0;
            	for (int i=0;i<TestMat->NumberOfClasses();i++)
				{
					FN[i]=0;
					FP[i]=0;
					TN[i]=0;
					precision[i]=0.0;
					Recall[i]=0.0;
				}


            for (int i=0;i<TestMat->NumberOfClasses();i++)
					for (int j=0;j<TestMat->NumberOfClasses();j++)
						if(j!=i)
							FP[i]+=classmat[i][j];

			for (int i=0;i<TestMat->NumberOfClasses();i++)
					for (int j=0;j<TestMat->NumberOfClasses();j++)
						if(j!=i)
                  FN[i]+=classmat[j][i];

			 for (int i=0;i<TestMat->NumberOfClasses();i++)					
                 sumTP+=classmat[i][i];
             
			 for (int k=0;k<TestMat->NumberOfClasses();k++)
						
                  TN[k]=sumTP-classmat[k][k];

             for (int m=0;m<TestMat->NumberOfClasses();m++)
				if(	classmat[m][m]+ FP[m] == 0)
                    precision[m]=0.0;
				else
					precision[m]=classmat[m][m]/(float)(classmat[m][m]+FP[m]);

			 for (int v=0;v<TestMat->NumberOfClasses();v++)
				if(classmat[v][v]+FN[v] == 0)
                   Recall[v]=0.0;
				else
                   Recall[v]=classmat[v][v]/(float)(classmat[v][v]+FN[v]);
                
              float AvgPrecision = 0.0;
			  float SumPrecision = 0.0;
			  float SumRecall = 0.0;
              float AvgRecall = 0.0;
              for (int z=0;z<TestMat->NumberOfClasses();z++)
			  {
				  SumPrecision+=precision[z];
				  SumRecall+=Recall[z];
			  }


                delete []TN;
                delete []FN;
				delete []FP;
                delete [] Recall;
				delete [] precision;
				for(int i = 0; i < TestMat->NumberOfClasses(); ++i) {
                   delete [] classmat[i];
                }
                delete [] classmat;
           
            AvgRecall=SumRecall/(float)TestMat->NumberOfClasses();
            AvgPrecision=SumPrecision/(float)TestMat->NumberOfClasses();
			AvgRecall=Math::Round(AvgRecall,4.0);
			AvgPrecision=Math::Round(AvgPrecision,4.0);


			sum=sum/(float) TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat(" KNN 2rnd-Btree accuracy: ",sum.ToString(),"  Recall :",AvgRecall.ToString(),"  Precision:",AvgPrecision.ToString());
			this->richTextBox2->AppendText("k= " + this->textBox2->Text + label8->Text);

		 }
private: System::Void trainBtr2pMinMaxNormToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
//this method train a binary search tree where each node store a number of training examples 
//based on their similarity to two points the one with the min norm, and the other with the max norm from the training data, 
//similar points to p1 are stored to the left node 
//similar points to p2 are stored to the right of the Btree, 
//the examples are then clustered in a Bsearch tree 
//until they become one point, which is stored stored in a leaf node.
//searching this tree is very fast (dlog n) and will increase the KNN speed 
//we will make it (log n) in the future by saving the probibilties of each class for each node  
			 if (tree2MnMxNorms){
				 delete tree2MnMxNorms; tree2MnMxNorms=0;
			 }
			int k=Convert::ToInt32(this->textBox2->Text);
			long n=TrainMat->Row();
			TrainMat->UpdateNorms(DistanceType);
			//double *norms=new double[n];
			//for (long i=0;i<n;i++)
				//norms[i]=TrainMat->Norms[i];
			Stopwatch ^timer = gcnew Stopwatch();  timer->Start(); 
			tree2MnMxNorms=new Tree2MnMxNorms(TrainMat,DistanceType);
			timer->Stop();
			String ^str11=GlobalfName->Substring(GlobalfName->LastIndexOf("\\")+1);
			this->richTextBox2->AppendText(String::Concat("\n", str11,"\ttime Elapsed to build 2 Points Min/Max norms Bintree\t", timer->ElapsedMilliseconds.ToString(),"\t"));

			label8->Text=String::Concat("Binary tree of 2 Points Min/Max norms is created : ","\t");
			if (this->checkBox3->Checked)
				tree2MnMxNorms->TraversBreadth();//this print the tree on a text file DrawTree.txt*/
			printtreestats2MinMaxpnt(); 
			//delete tree; tree=0;
			//print tree stats

		 }
private: System::Void testTree2pmnmxToLeafToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//this search for all examples in the test set in the created 2 pnts of min/max norms in binary tree until 
	//reaching a leafe node to return, which may/may not contain one example
			// TestMat->UpdateNorms(DistanceType);
			 float MaxV=-99999999999999999.0;
			for (long rr=0;rr<TrainMat->Row();rr++){
				float cl=TrainMat->classint[rr];
				if (cl > MaxV)
					MaxV=cl;
			}
			 float sum=0;
			 long *classinttwo=new long[TestMat->Row()];
			 long *classinttoo=new long[TestMat->Row()];
			 long * FN=new long[TestMat->NumberOfClasses()];
			 long * FP=new long[TestMat->NumberOfClasses()];
			 long * TN=new long[TestMat->NumberOfClasses()];
			 float * precision=new float[TestMat->NumberOfClasses()];
			 float * Recall=new float[TestMat->NumberOfClasses()];
             ArrayList^n=gcnew ArrayList();
		    long** classmat = new long*[TestMat->NumberOfClasses()];
            for(long i = 0; i < TestMat->NumberOfClasses(); ++i)
            classmat[i] = new long[TestMat->NumberOfClasses()];
			 for (long i=0;i<TestMat->Row();i++)
				{
					if ( ! n->Contains(TestMat->classint[i]))
						n->Add(TestMat->classint[i]);
			    }
//classification================================================================
				int k=Convert::ToInt32(this->textBox2->Text);
				this->progressBar1->Maximum=TestMat->Row();this->progressBar1->Value=0;
				Stopwatch ^timer = gcnew Stopwatch();  timer->Start();  
				for (long i=0;i<TestMat->Row();i++){
					//get the first test example 
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					//get the training indexes from the tree 
					BTreeNode * temp=tree2MnMxNorms->GetExamples(TrainMat,TestMat, i,DistanceType);
					long cs=knnBtree(TrainMat,testRow,k,temp, MaxV);
					if (this->checkBox3->Checked)
						this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					classinttwo[i]=cs;
					classinttoo[i]=TestMat->classint[i];
					delete []testRow; testRow=0;
					this->progressBar1->Value++; Application::DoEvents();
				}
				timer->Stop();
//end classification=============================================================
			String ^str11=GlobalfName->Substring(GlobalfName->LastIndexOf("\\")+1);
				
				this->richTextBox2->AppendText(String::Concat("\n",str11,"\ttime Elapsed KNN 2min/max-norms-Pts-tree\t", timer->ElapsedMilliseconds.ToString(),"\n"));

				long index1=0;
				long index2=0;
				for (long i=0;i<TestMat->NumberOfClasses();i++)
					for (long j=0;j<TestMat->NumberOfClasses();j++)
						classmat[i][j]=0;

                //confusion matrix 
				for (long i=0;i<TestMat->Row();i++){
				    index1=n->IndexOf(classinttoo[i]);
					index2=n->IndexOf(classinttwo[i]);  
					if(classinttoo[i]== classinttwo[i])
						classmat[index1][index1]+=1;
					else
						classmat[index1][index2]+=1;

				}
                   
                delete []classinttoo;
                delete []classinttwo;


				int sumTP = 0;
            	for (int i=0;i<TestMat->NumberOfClasses();i++)
				{
					FN[i]=0;
					FP[i]=0;
					TN[i]=0;
					precision[i]=0.0;
					Recall[i]=0.0;
				}


            for (int i=0;i<TestMat->NumberOfClasses();i++)
					for (int j=0;j<TestMat->NumberOfClasses();j++)
						if(j!=i)
							FP[i]+=classmat[i][j];

			for (int i=0;i<TestMat->NumberOfClasses();i++)
					for (int j=0;j<TestMat->NumberOfClasses();j++)
						if(j!=i)
                  FN[i]+=classmat[j][i];

			 for (int i=0;i<TestMat->NumberOfClasses();i++)					
                 sumTP+=classmat[i][i];
             
			 for (int k=0;k<TestMat->NumberOfClasses();k++)
						
                  TN[k]=sumTP-classmat[k][k];

             for (int m=0;m<TestMat->NumberOfClasses();m++)
				if(	classmat[m][m]+ FP[m] == 0)
                    precision[m]=0.0;
				else
					precision[m]=classmat[m][m]/(float)(classmat[m][m]+FP[m]);

			 for (int v=0;v<TestMat->NumberOfClasses();v++)
				if(classmat[v][v]+FN[v] == 0)
                   Recall[v]=0.0;
				else
                   Recall[v]=classmat[v][v]/(float)(classmat[v][v]+FN[v]);
                
              float AvgPrecision = 0.0;
			  float SumPrecision = 0.0;
			  float SumRecall = 0.0;
              float AvgRecall = 0.0;
              for (int z=0;z<TestMat->NumberOfClasses();z++)
			  {
				  SumPrecision+=precision[z];
				  SumRecall+=Recall[z];
			  }


                delete []TN;
                delete []FN;
				delete []FP;
                delete [] Recall;
				delete [] precision;
				for(int i = 0; i < TestMat->NumberOfClasses(); ++i) {
                   delete [] classmat[i];
                }
                delete [] classmat;
           
            AvgRecall=SumRecall/(float)TestMat->NumberOfClasses();
            AvgPrecision=SumPrecision/(float)TestMat->NumberOfClasses();
			AvgRecall=Math::Round(AvgRecall,4.0);
			AvgPrecision=Math::Round(AvgPrecision,4.0);


			sum=sum/(float) TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat("2 pnts of min/max-norms-Btree accuracy\t",sum.ToString(),"\tRecall\t",AvgRecall.ToString(),"\tPrecision\t",AvgPrecision.ToString(),"\n");
			this->richTextBox2->AppendText("k= " + this->textBox2->Text + label8->Text);

		 }
private: System::Void testAllWithNFoldToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			ArrayList ^ AllData =MatToArrayList(TrainMat);
			long n=AllData->Count;
			long * Rndindxes = new long[n];
			int nfold=Convert::ToInt32(this->textBox5->Text);
			for (long i=0;i<n;i++)
				Rndindxes[i]=i;
			for (long i=0;i<n;i++){
				long index=rnd->Next(0,n);
				//swap index by its location
				long temp=Rndindxes[index];
				Rndindxes[index]=Rndindxes[i];
				Rndindxes[i]=temp;
			}
			
			long stride= n/nfold;
			
	for (long i=0, ii=1; ii <= nfold; ii++,i+=stride){
		//initilize array of test indexes
		long * testIndexes=new long[stride];
		for(long j=0; j<stride;j++)
			testIndexes[j]=Rndindxes[i+j];
		TrainTestMats ttm;
		ttm =ArrayListToMat(AllData,testIndexes,stride);//split data to train test 
		delete [] testIndexes;testIndexes=0;
		if (TrainMat){
			delete TrainMat; TrainMat=0;}
		if (TestMat){
			delete TestMat; TestMat=0;}
		TrainMat=ttm.train;
		TestMat=ttm.test;
		//fold 
		this->richTextBox2->AppendText("\nFold...("+ii.ToString()+").............\n");
		//train norm
		train01NormsBtreeToolStripMenuItem_Click(sender, e);
		//test
		test01NormsBtreeNNToolStripMenuItem_Click(sender, e);
			 if (tree){
				 delete tree; tree=0;
			 }

		//train 2 rnd pnts tree
		trainBtreeToolStripMenuItem_Click(sender, e);
		//test
		testTreeToLeafToolStripMenuItem_Click(sender, e);
			 if (tree2rndp){
				 delete tree2rndp; tree2rndp=0;
			 }

		//train 2min-max normas
		trainBtr2pMinMaxNormToolStripMenuItem_Click(sender, e);
		//test
		testTree2pmnmxToLeafToolStripMenuItem_Click(sender, e);
			 if (tree2MnMxNorms){
				 delete tree2MnMxNorms; tree2MnMxNorms=0;
			 }


	Application::DoEvents();
	}

delete [] Rndindxes;Rndindxes=0;

//return train mat as it is 
	if (TrainMat){
		delete TrainMat; TrainMat=0;}

	TrainMat=ArrayListToMat(AllData);
		 }
private: System::Void openTheFirst1000RowsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
//this open the Train file without using ms object to hold big data, c File open with dynamic arrays 
 String ^ filename="";
 System::Windows::Forms::DialogResult dresult;
 dresult=ofdlg1->ShowDialog();
 System::Windows::Forms::DialogResult ok =System::Windows::Forms::DialogResult::OK;
 if (dresult ==ok){
   filename=ofdlg1->FileName;
   GlobalfName=filename;

//c file count
	IntPtr ptrToNativeString = Marshal::StringToHGlobalAnsi(filename);
    char* nativeString = static_cast<char*>(ptrToNativeString.ToPointer());

//get the first line to know the number of columns in the dataset===========
 col=0;
  FILE *fp = fopen(nativeString,"r");
  char ch='0';
	String ^line="";
	while(!feof(fp) && ch != '\n'){
		ch = fgetc(fp);
		String ^str=gcnew String(&ch);
		line=line + str;
	}
  fclose(fp);
//get the dilimination type====================================================
  	String^ delimStr;//= " ";
	long indexofcomma=line->IndexOf(",");
	if (indexofcomma > 0 && indexofcomma < line->Length-1)
		delimStr= ",";
	else
		delimStr= " ";

	array<Char>^ delimiter = delimStr->ToCharArray( );
	array<String^>^ WordsNumbers;
	WordsNumbers = line->Split(delimiter);
	col=WordsNumbers->Length-1;//subtractting the class column.
//now get the number of lines (records)==============================================
  long lines=0;
  /*fp = fopen(nativeString,"r"); 

	while(!feof(fp)){
		ch = fgetc(fp);
		if(ch == '\n'){
			lines++;
		}
	}
  fclose(fp
  */
//try ms readfile
  System::IO::FileInfo  ^fleMembers = gcnew FileInfo(filename);
  StreamReader ^swrMembers = fleMembers->OpenText();
  line = swrMembers->ReadLine();
  while (line) {
	lines++;
	line = swrMembers->ReadLine();
	  }
  swrMembers->Close();

  //			swrMembers->
			  //int dd=fleMembers->Length-48;
  

  this->richTextBox1->AppendText("\nnumber of records:" + lines.ToString());
	row = lines;
	 
	if (TrainMat){delete TrainMat; TrainMat=0;}
	if (TestMat){delete TestMat; TestMat=0;}
	TrainMat=new Mat(row,col);
	this->progressBar1->Maximum=row;
	progressBar1->Value=0;

//now fill the matrix with the dataset values==========================================
/*
 fp = fopen(nativeString,"r");
	lines=0;
	line="";
	while(!feof(fp)){
		ch = fgetc(fp);
		if(ch == '\n'){
			WordsNumbers = line->Split(delimiter);
			if (this->checkBox4->Checked)
				for( long j=1;j<col+1;j++)
					TrainMat->set(lines,j-1,Convert::ToDouble(WordsNumbers[j]));
			else
				for( long j=0;j<col;j++)
					TrainMat->set(lines,j,Convert::ToDouble(WordsNumbers[j]));
			if (this->checkBox4->Checked)
				TrainMat->classint[lines] = Convert::ToInt32(Convert::ToDouble(WordsNumbers[0]));
			else
				TrainMat->classint[lines] = Convert::ToInt32(Convert::ToDouble(WordsNumbers[col]));

			progressBar1->Value++;
			Application::DoEvents();
			line="";//tostart a new line
			lines++;
		}
		else{
			String ^str=gcnew String(&ch);
			line=line + str;
		}
	}
 fclose(fp);
 */
	//ms implementation to use read line faster
	fleMembers = gcnew FileInfo(filename);
	swrMembers = fleMembers->OpenText();
	line = swrMembers->ReadLine();
	lines = 0;
	while (line) {
		
		WordsNumbers = line->Split(delimiter);
		if (this->checkBox4->Checked)
			for (long j = 1;j < col + 1;j++)
				TrainMat->set(lines, j - 1, Convert::ToDouble(WordsNumbers[j]));
		else
			for (long j = 0;j < col;j++)
				TrainMat->set(lines, j, Convert::ToDouble(WordsNumbers[j]));
		if (this->checkBox4->Checked)
			TrainMat->classint[lines] = Convert::ToInt32(Convert::ToDouble(WordsNumbers[0]));
		else
			TrainMat->classint[lines] = Convert::ToInt32(Convert::ToDouble(WordsNumbers[col]));

		progressBar1->Value++;
		Application::DoEvents();
		//tostart a new line
		lines++;
		line = swrMembers->ReadLine();
	}
	swrMembers->Close();

//========
				//std::ifstream fleMembers(filename->ToCharArray());
				
				this->richTextBox1->AppendText(String::Concat("\nTrain File: ,",filename, "  Loaded ......\n"));
				String ^temp;
				temp="number of vars:";
				temp=String::Concat(temp,(col).ToString(),"\n");
				temp=String::Concat(temp,"number of Examples: ",TrainMat->Row().ToString(),"\n");
				TrainMat->setMaxes();
				this->richTextBox1->AppendText(temp);
				temp=temp->Replace("\n", " ");
				this->label3->Text=temp;
 }

		 }
private: System::Void testALLWithNFoldEfficientToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //nfold test for the 3 tree methods
			Mat * AllDATA=TrainMat;
			long n=AllDATA->Row();
			long * Rndindxes = new long[n];
			int nfold=Convert::ToInt32(this->textBox5->Text);
			for (long i=0;i<n;i++)
				Rndindxes[i]=i;
			for (long i=0;i<n;i++){
				long index=rnd->Next(0,n);
				//swap index by its location
				long temp=Rndindxes[index];
				Rndindxes[index]=Rndindxes[i];
				Rndindxes[i]=temp;
			}
			
			long stride= n/nfold;
			
	for (long i=0, ii=1; ii <= nfold; ii++,i+=stride){
		//initilize array of test indexes
		long * testIndexes=new long[stride];
		for(long j=0; j<stride;j++)
			testIndexes[j]=Rndindxes[i+j];
		TrainTestMats ttm;
	//	ttm =ArrayListToMat(AllData,testIndexes,stride);//split data to train test 
		ttm =MatToMats(AllDATA,testIndexes,stride);//split data to train and test 
		delete [] testIndexes;testIndexes=0;
		TrainMat=ttm.train;
		TestMat=ttm.test;
		//fold 
		this->richTextBox2->AppendText("\nDT"+this->textBox4->Text+" Fold...("+ii.ToString()+").............\n");
		//Train 2 extreme points
		//trainBST2ExtremPointsToolStripMenuItem_Click(sender, e);
		//test
		/*
		trainFurthestPBSTToolStripMenuItem_Click(sender, e);
		testFurthestPBSTToolStripMenuItem_Click(sender, e); 
			 if (tree2furthestPts){
				 delete tree2furthestPts; tree2furthestPts=0;
			 }
			*/ 

		furthestPointDTToolStripMenuItem_Click(sender, e);
		testFurthesPointDTToolStripMenuItem_Click(sender, e); 
			 if (dt2furthestPts){
				 delete dt2furthestPts; dt2furthestPts=0;
			 }

		//testBST2ExtremPointsToolStripMenuItem_Click(sender, e);
		//	 if (tree2ExtremePts){
		//		 delete tree2ExtremePts; tree2ExtremePts=0;
		//	 }

	/*	//train norm
		train01NormsBtreeToolStripMenuItem_Click(sender, e);
		//test
		test01NormsBtreeNNToolStripMenuItem_Click(sender, e);
			 if (tree){
				 delete tree; tree=0;
			 }

		//train 2 rnd pnts tree
		trainBtreeToolStripMenuItem_Click(sender, e);
		//test
		testTreeToLeafToolStripMenuItem_Click(sender, e);
			 if (tree2rndp){
				 delete tree2rndp; tree2rndp=0;
			 }

		//train 2min-max normas
		trainBtr2pMinMaxNormToolStripMenuItem_Click(sender, e);
		//test
		testTree2pmnmxToLeafToolStripMenuItem_Click(sender, e);
			 if (tree2MnMxNorms){
				 delete tree2MnMxNorms; tree2MnMxNorms=0;
			 }
 the previous are old tests*/

		if (TrainMat){
			delete TrainMat; TrainMat=0;}
		if (TestMat){
			delete TestMat; TestMat=0;}
	Application::DoEvents();
	}

delete [] Rndindxes;Rndindxes=0;

//return train mat as it is 
	if (TrainMat){
		delete TrainMat; TrainMat=0;}

	TrainMat=AllDATA;
		 }
private: System::Void openTestFileEfficiemtlyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
//this open the Test file without using ms object to hold big data, c File open with dynamic arrays 
 String ^ filename="";
 System::Windows::Forms::DialogResult dresult;
 dresult=ofdlg1->ShowDialog();
 System::Windows::Forms::DialogResult ok =System::Windows::Forms::DialogResult::OK;
 if (dresult ==ok){
   filename=ofdlg1->FileName;
   GlobalfName=filename;

//c file count
	IntPtr ptrToNativeString = Marshal::StringToHGlobalAnsi(filename);
    char* nativeString = static_cast<char*>(ptrToNativeString.ToPointer());

//get the first line to know the number of columns in the dataset===========
 col=0;
  FILE *fp = fopen(nativeString,"r");
  char ch='0';
	String ^line="";
	while(!feof(fp) && ch != '\n'){
		ch = fgetc(fp);
		String ^str=gcnew String(&ch);
		line=line + str;
	}
  fclose(fp);
//get the dilimination type====================================================
  	String^ delimStr;//= " ";
	long indexofcomma=line->IndexOf(",");
	if (indexofcomma > 0 && indexofcomma < line->Length-1)
		delimStr= ",";
	else
		delimStr= " ";

	array<Char>^ delimiter = delimStr->ToCharArray( );
	array<String^>^ WordsNumbers;
	WordsNumbers = line->Split(delimiter);
	col=WordsNumbers->Length-1;//subtractting the class column.
//now get the number of lines (records)==============================================
  long lines=0;
  fp = fopen(nativeString,"r");
	while(!feof(fp)){
		ch = fgetc(fp);
		if(ch == '\n'){
			lines++;
		}
	}
  fclose(fp);

  this->richTextBox1->AppendText("\nnumber of records:" + lines.ToString());
	row = lines;
	if (TestMat){delete TestMat; TestMat=0;}
	TestMat=new Mat(row,col);//create dataset
	this->progressBar1->Maximum=row;
	progressBar1->Value=0;

//now fill the matrix with the dataset values  ==========================================

 fp = fopen(nativeString,"r");
	lines=0;
	line="";
	while(!feof(fp)){
		ch = fgetc(fp);
		if(ch == '\n'){
			WordsNumbers = line->Split(delimiter);
			if (this->checkBox4->Checked)
				for( long j=1;j<col+1;j++)
					TestMat->set(lines,j-1,Convert::ToDouble(WordsNumbers[j]));
			else
				for( long j=0;j<col;j++)
					TestMat->set(lines,j,Convert::ToDouble(WordsNumbers[j]));
			if (this->checkBox4->Checked)
				TestMat->classint[lines] = Convert::ToInt32(Convert::ToDouble(WordsNumbers[0]));
			else
				TestMat->classint[lines] = Convert::ToInt32(Convert::ToDouble(WordsNumbers[col]));

			progressBar1->Value++;
			Application::DoEvents();
			line="";//tostart a new line
			lines++;
		}
		else{
			String ^str=gcnew String(&ch);
			line=line + str;
		}
	}
 fclose(fp);

//========
				//std::ifstream fleMembers(filename->ToCharArray());
				
				this->richTextBox2->AppendText(String::Concat("\nTest File: ,",filename, "  Loaded ......\n"));
				String ^temp;
				temp="number of vars:";
				temp=String::Concat(temp,(col).ToString(),"\n");
				temp=String::Concat(temp,"number of Examples: ",TestMat->Row().ToString(),"\n");
				TestMat->setMaxes();
				this->richTextBox2->AppendText(temp);
				temp=temp->Replace("\n", " ");
				this->label15->Text=temp;
 }
		 }


/////////////////////////////end of Form 1 ///////////////////////////
private: System::Void testAllOnReadyTrainAndTestToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {


		trainFurthestPBSTToolStripMenuItem_Click(sender, e);
		testFurthestPBSTToolStripMenuItem_Click(sender, e); 
			 if (tree2furthestPts){
				 delete tree2furthestPts; tree2furthestPts=0;
			 }



/*
			 //train norm
		train01NormsBtreeToolStripMenuItem_Click(sender, e);
		//test
		test01NormsBtreeNNToolStripMenuItem_Click(sender, e);
			 if (tree){
				 delete tree; tree=0;
			 }

		//train 2 rnd pnts tree
		trainBtreeToolStripMenuItem_Click(sender, e);
		//test
		testTreeToLeafToolStripMenuItem_Click(sender, e);
			 if (tree2rndp){
				 delete tree2rndp; tree2rndp=0;
			 }

		//train 2min-max normas
		trainBtr2pMinMaxNormToolStripMenuItem_Click(sender, e);
		//test
		testTree2pmnmxToLeafToolStripMenuItem_Click(sender, e);
			 if (tree2MnMxNorms){
				 delete tree2MnMxNorms; tree2MnMxNorms=0;
			 }
*/
		 }
private: System::Void kNNNFoldsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //nfold test for the 3 tree methods
			Mat * AllDATA=TrainMat;
			long n=AllDATA->Row();
			long * Rndindxes = new long[n];
			int nfold=Convert::ToInt32(this->textBox5->Text);
			for (long i=0;i<n;i++)
				Rndindxes[i]=i;
			for (long i=0;i<n;i++){
				long index=rnd->Next(0,n);
				//swap index by its location
				long temp=Rndindxes[index];
				Rndindxes[index]=Rndindxes[i];
				Rndindxes[i]=temp;
			}
			
			long stride= n/nfold;
			
	for (long i=0, ii=1; ii <= nfold; ii++,i+=stride){
		//initilize array of test indexes
		long * testIndexes=new long[stride];
		for(long j=0; j<stride;j++)
			testIndexes[j]=Rndindxes[i+j];
		TrainTestMats ttm;
	//	ttm =ArrayListToMat(AllData,testIndexes,stride);//split data to train test 
		ttm =MatToMats(AllDATA,testIndexes,stride);//split data to train and test 
		delete [] testIndexes;testIndexes=0;
		TrainMat=ttm.train;
		TestMat=ttm.test;
		//fold 
		this->richTextBox2->AppendText("\nFold...("+ii.ToString()+").............\n");
		
		//test knn
		kNNToolStripMenuItem_Click(sender, e);

		if (TrainMat){
			delete TrainMat; TrainMat=0;}
		if (TestMat){
			delete TestMat; TestMat=0;}
	Application::DoEvents();
	}

delete [] Rndindxes;Rndindxes=0;

//return train mat as it is 
	if (TrainMat){
		delete TrainMat; TrainMat=0;}

	TrainMat=AllDATA;
		 }
private: System::Void trainBST2ExtremPointsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
//this method train a binary search tree where each node store a number of training examples 
//based on their similarity to two local points P1 and P2,
//P1 is the closest point in a node to the global extreme min point
//P2 is the closest point in a node to the global extreme max point, 
//the closetes points to P1 are stored to the left node
//the closetes points to P2 are stored to the right node 
//the examples are then clustered in a Bsearch tree 
//until they become one point, whch is stored in a leaf node.
//searching this tree is very fast (dlog n) and will increase the KNN speed 


			 //ensure that the global extreme ponts are updated
			 TrainMat->setMaxes();
			 if (tree2ExtremePts){
				 delete tree2ExtremePts; tree2ExtremePts=0;
			 }
			int k=Convert::ToInt32(this->textBox2->Text);
			long n=TrainMat->Row();
			Stopwatch ^timer = gcnew Stopwatch();  timer->Start(); 
			tree2ExtremePts=new Tree2PclosesttoExtreme(TrainMat,DistanceType);
			timer->Stop();
			String ^str11=GlobalfName->Substring(GlobalfName->LastIndexOf("\\")+1);
			this->richTextBox2->AppendText(String::Concat("\n", str11,"\tTime to build 2 Extreme points BST\t", timer->ElapsedMilliseconds.ToString(),"\t"));

			label8->Text=String::Concat("BST of 2 Extreme points is created : ","\t");
			if (this->checkBox3->Checked)
				tree2ExtremePts->TraversBreadth();//this print the tree on a text file DrawTree.txt*/
			PrintStat2ExtrmPntsTree(); 
		
		 }
private: System::Void testBST2ExtremPointsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//this search for all examples in the test set in the created BST of 2 Extreme points until 
	//reaching a leafe node to return, which may/may not contain one example
			// TestMat->UpdateNorms(DistanceType);
			 float MaxV=-99999999999999999.0;
			for (long rr=0;rr<TrainMat->Row();rr++){
				float cl=TrainMat->classint[rr];
				if (cl > MaxV)
					MaxV=cl;
			}
			 float sum=0;
			 long *classinttwo=new long[TestMat->Row()];
			 long *classinttoo=new long[TestMat->Row()];
			 long * FN=new long[TestMat->NumberOfClasses()];
			 long * FP=new long[TestMat->NumberOfClasses()];
			 long * TN=new long[TestMat->NumberOfClasses()];
			 float * precision=new float[TestMat->NumberOfClasses()];
			 float * Recall=new float[TestMat->NumberOfClasses()];
             ArrayList^n=gcnew ArrayList();
		    long** classmat = new long*[TestMat->NumberOfClasses()];
            for(long i = 0; i < TestMat->NumberOfClasses(); ++i)
            classmat[i] = new long[TestMat->NumberOfClasses()];
			 for (long i=0;i<TestMat->Row();i++)
				{
					if ( ! n->Contains(TestMat->classint[i]))
						n->Add(TestMat->classint[i]);
			    }
//classification================================================================
				int k=Convert::ToInt32(this->textBox2->Text);
				this->progressBar1->Maximum=TestMat->Row();this->progressBar1->Value=0;
				Stopwatch ^timer = gcnew Stopwatch();  timer->Start();  
				for (long i=0;i<TestMat->Row();i++){
					//get the first test example 
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					//get the training indexes from the BST of 2 extrm pnts tree 
					BTreeNode * temp=tree2ExtremePts->GetExamples(TrainMat,TestMat, i,DistanceType);
					long cs=knnBtree(TrainMat,testRow,k,temp, MaxV);
					if (this->checkBox3->Checked)
						this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					classinttwo[i]=cs;
					classinttoo[i]=TestMat->classint[i];
					delete []testRow; testRow=0;
					this->progressBar1->Value++; Application::DoEvents();
				}
				timer->Stop();
//end classification=============================================================
			String ^str11=GlobalfName->Substring(GlobalfName->LastIndexOf("\\")+1);
				
				this->richTextBox2->AppendText(String::Concat("\n",str11,"\ttime for testing 2Extrem Pts-BST\t", timer->ElapsedMilliseconds.ToString(),"\n"));

				long index1=0;
				long index2=0;
				for (long i=0;i<TestMat->NumberOfClasses();i++)
					for (long j=0;j<TestMat->NumberOfClasses();j++)
						classmat[i][j]=0;

                //confusion matrix 
				for (long i=0;i<TestMat->Row();i++){
				    index1=n->IndexOf(classinttoo[i]);
					index2=n->IndexOf(classinttwo[i]);  
					if(classinttoo[i]== classinttwo[i])
						classmat[index1][index1]+=1;
					else
						classmat[index1][index2]+=1;

				}
                   
                delete []classinttoo;
                delete []classinttwo;


				int sumTP = 0;
            	for (int i=0;i<TestMat->NumberOfClasses();i++)
				{
					FN[i]=0;
					FP[i]=0;
					TN[i]=0;
					precision[i]=0.0;
					Recall[i]=0.0;
				}


            for (int i=0;i<TestMat->NumberOfClasses();i++)
					for (int j=0;j<TestMat->NumberOfClasses();j++)
						if(j!=i)
							FP[i]+=classmat[i][j];

			for (int i=0;i<TestMat->NumberOfClasses();i++)
					for (int j=0;j<TestMat->NumberOfClasses();j++)
						if(j!=i)
                  FN[i]+=classmat[j][i];

			 for (int i=0;i<TestMat->NumberOfClasses();i++)					
                 sumTP+=classmat[i][i];
             
			 for (int k=0;k<TestMat->NumberOfClasses();k++)
						
                  TN[k]=sumTP-classmat[k][k];

             for (int m=0;m<TestMat->NumberOfClasses();m++)
				if(	classmat[m][m]+ FP[m] == 0)
                    precision[m]=0.0;
				else
					precision[m]=classmat[m][m]/(float)(classmat[m][m]+FP[m]);

			 for (int v=0;v<TestMat->NumberOfClasses();v++)
				if(classmat[v][v]+FN[v] == 0)
                   Recall[v]=0.0;
				else
                   Recall[v]=classmat[v][v]/(float)(classmat[v][v]+FN[v]);
                
              float AvgPrecision = 0.0;
			  float SumPrecision = 0.0;
			  float SumRecall = 0.0;
              float AvgRecall = 0.0;
              for (int z=0;z<TestMat->NumberOfClasses();z++)
			  {
				  SumPrecision+=precision[z];
				  SumRecall+=Recall[z];
			  }


                delete []TN;
                delete []FN;
				delete []FP;
                delete [] Recall;
				delete [] precision;
				for(int i = 0; i < TestMat->NumberOfClasses(); ++i) {
                   delete [] classmat[i];
                }
                delete [] classmat;
           
            AvgRecall=SumRecall/(float)TestMat->NumberOfClasses();
            AvgPrecision=SumPrecision/(float)TestMat->NumberOfClasses();
			AvgRecall=Math::Round(AvgRecall,4.0);
			AvgPrecision=Math::Round(AvgPrecision,4.0);


			sum=sum/(float) TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat(" 2extrem points BST accuracy\t",sum.ToString(),"\tRecall\t",AvgRecall.ToString(),"\tPrecision:",AvgPrecision.ToString());
			this->richTextBox2->AppendText("k= " + this->textBox2->Text + label8->Text);

		 }
private: System::Void trainFurthestPBSTToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
//this method train a binary search tree where each node store a number of training examples 
//based on their similarity to two local furthest points P1 and P2(diameter), 
//we used A2 algorithm (hill climbing) to find P1 and P2
//the closetes examples to P1 are stored to the left node
//the closetes points to P2 are stored to the right node 
//the examples are then clustered in a Bsearch tree 
//until they become one point, whch is stored in a leaf node.
//searching this tree is very fast (dlog n) and thus increases the KNN speed 


			 //ensure that the norms are updated so to be used if p1 pt needs swapp
			 TrainMat->UpdateNorms(DistanceType);
			 if (tree2furthestPts){
				 delete tree2furthestPts; tree2furthestPts=0;
			 }
			int k=Convert::ToInt32(this->textBox2->Text);
			long n=TrainMat->Row();
			Stopwatch ^timer = gcnew Stopwatch();  timer->Start(); 
			tree2furthestPts=new Tree2FurthestPoints(TrainMat,DistanceType);
			timer->Stop();
			String ^str11=GlobalfName->Substring(GlobalfName->LastIndexOf("\\")+1);
			this->richTextBox2->AppendText(String::Concat("\n", str11,"\tTime to build 2 Furthest points BST\t", timer->ElapsedMilliseconds.ToString(),"\t"));

			label8->Text=String::Concat("BST of 2 Furthest points is created : ","\t");
			if (this->checkBox3->Checked)
				tree2furthestPts->TraversBreadth();//this print the tree on a text file DrawTree.txt*/
			PrintStatTree2FurthestPoints(); 
	
		 }

////////////////////////end form1 //////////////////////////////////////////////////////////////
private: System::Void testFurthestPBSTToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//this search for all examples in the test set in the created BST of 2 furthest points until 
	//reaching a leafe node to return, which may/may not contain one example
			TestMat->UpdateNorms(DistanceType);
			 float MaxV=-99999999999999999.0;
			for (long rr=0;rr<TrainMat->Row();rr++){
				float cl=TrainMat->classint[rr];
				if (cl > MaxV)
					MaxV=cl;
			}
			 float sum=0;
		/*	 long *classinttwo=new long[TestMat->Row()];
			 long *classinttoo=new long[TestMat->Row()];
			 long * FN=new long[TestMat->NumberOfClasses()];
			 long * FP=new long[TestMat->NumberOfClasses()];
			 long * TN=new long[TestMat->NumberOfClasses()];
			 double * precision=new double[TestMat->NumberOfClasses()];
			 double * Recall=new double[TestMat->NumberOfClasses()];
             ArrayList^n=gcnew ArrayList();
		    long** classmat = new long*[TestMat->NumberOfClasses()];
            for(long i = 0; i < TestMat->NumberOfClasses(); ++i)
            classmat[i] = new long[TestMat->NumberOfClasses()];
			 for (long i=0;i<TestMat->Row();i++)
				{
					if ( ! n->Contains(TestMat->classint[i]))
						n->Add(TestMat->classint[i]);
			    }
				*/
//classification================================================================
				int k=Convert::ToInt32(this->textBox2->Text);
				this->progressBar1->Maximum=TestMat->Row();this->progressBar1->Value=0;
				Stopwatch ^timer = gcnew Stopwatch();  timer->Start();  
				for (long i=0;i<TestMat->Row();i++){
					//get the first test example 
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					//get the training indexes from the BST of 2 extrm pnts tree 
					BTreeNode * temp=tree2furthestPts->GetExamples(TrainMat,TestMat, i,DistanceType);
					long cs=knnBtree(TrainMat,testRow,k,temp, MaxV);
					if (this->checkBox3->Checked)
						this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					//classinttwo[i]=cs;
					//classinttoo[i]=TestMat->classint[i];
					delete []testRow; testRow=0;
					this->progressBar1->Value++; Application::DoEvents();
				}
				timer->Stop();
//end classification=============================================================
			String ^str11=GlobalfName->Substring(GlobalfName->LastIndexOf("\\")+1);
				
				this->richTextBox2->AppendText(String::Concat("\n",str11,"\ttime for testing 2 Furthest Pts-BST\t", timer->ElapsedMilliseconds.ToString(),"\n"));

			/*	long index1=0;
				long index2=0;
				for (long i=0;i<TestMat->NumberOfClasses();i++)
					for (long j=0;j<TestMat->NumberOfClasses();j++)
						classmat[i][j]=0;

                //confusion matrix 
				for (long i=0;i<TestMat->Row();i++){
				    index1=n->IndexOf(classinttoo[i]);
					index2=n->IndexOf(classinttwo[i]);  
					if(classinttoo[i]== classinttwo[i])
						classmat[index1][index1]+=1;
					else
						classmat[index1][index2]+=1;

				}
                   
                delete []classinttoo;
                delete []classinttwo;


				int sumTP = 0;
            	for (int i=0;i<TestMat->NumberOfClasses();i++)
				{
					FN[i]=0;
					FP[i]=0;
					TN[i]=0;
					precision[i]=0.0;
					Recall[i]=0.0;
				}


            for (int i=0;i<TestMat->NumberOfClasses();i++)
					for (int j=0;j<TestMat->NumberOfClasses();j++)
						if(j!=i)
							FP[i]+=classmat[i][j];

			for (int i=0;i<TestMat->NumberOfClasses();i++)
					for (int j=0;j<TestMat->NumberOfClasses();j++)
						if(j!=i)
                  FN[i]+=classmat[j][i];

			 for (int i=0;i<TestMat->NumberOfClasses();i++)					
                 sumTP+=classmat[i][i];
             
			 for (int k=0;k<TestMat->NumberOfClasses();k++)
						
                  TN[k]=sumTP-classmat[k][k];

             for (int m=0;m<TestMat->NumberOfClasses();m++)
				if(	classmat[m][m]+ FP[m] == 0)
                    precision[m]=0.0;
				else
					precision[m]=classmat[m][m]/(double)(classmat[m][m]+FP[m]);

			 for (int v=0;v<TestMat->NumberOfClasses();v++)
				if(classmat[v][v]+FN[v] == 0)
                   Recall[v]=0.0;
				else
                   Recall[v]=classmat[v][v]/(double)(classmat[v][v]+FN[v]);
                
              double AvgPrecision = 0.0;
			  double SumPrecision = 0.0;
			  double SumRecall = 0.0;
              double AvgRecall = 0.0;
              for (int z=0;z<TestMat->NumberOfClasses();z++)
			  {
				  SumPrecision+=precision[z];
				  SumRecall+=Recall[z];
			  }


                delete []TN;
                delete []FN;
				delete []FP;
                delete [] Recall;
				delete [] precision;
				for(int i = 0; i < TestMat->NumberOfClasses(); ++i) {
                   delete [] classmat[i];
                }
                delete [] classmat;
           
            AvgRecall=SumRecall/(double)TestMat->NumberOfClasses();
            AvgPrecision=SumPrecision/(double)TestMat->NumberOfClasses();
			AvgRecall=Math::Round(AvgRecall,4.0);
			AvgPrecision=Math::Round(AvgPrecision,4.0);
			*/

			sum=sum/(float) TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat(" 2 Furthest points BST accuracy\t",sum.ToString()/*,"\tRecall\t",AvgRecall.ToString(),"\tPrecision:",AvgPrecision.ToString()*/);
			this->richTextBox2->AppendText("k= " + this->textBox2->Text + label8->Text);

		 }
private: System::Void normBTreePerClassToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //this method creates a BST foe each class data based on the 01norm method, 
			 //these trees are used later to search for the nearest examples for a test example 
			 //the return examplse from all of the trees are used by the KNN to clisfy the test example 

			 if (Multi01NormTree){
				 for (int i=0;i<TreesNum;i++){
					delete Multi01NormTree[i];
				 }
				 delete Multi01NormTree; Multi01NormTree=0;
			 }
			TrainMat->UpdateClasses();
			TrainMat->UpdateNumRowPerClass();
			TreesNum=TrainMat->NumClasses;
			TrainMat->UpdateNorms(DistanceType);
			//test
			Stopwatch ^timer = gcnew Stopwatch();  timer->Start(); 
			Multi01NormTree= new Tree *[TreesNum];
			for (long cls=0;cls<TreesNum;cls++){
				Multi01NormTree[cls]=new Tree(TrainMat, cls,TrainMat->NumRowPerClass[cls]);
				//Tree * tree=Multi01NormTree[cls];
				printtreestats(Multi01NormTree[cls],TrainMat->NumRowPerClass[cls]); 
				Multi01NormTree[cls]->TraversBreadth();
				
			} 
			
//to here is ok

	//		int k=Convert::ToInt32(this->textBox2->Text);
	//		long n=TrainMat->Row();
			
	//		double *norms=new double[n];
	//		for (long i=0;i<n;i++)
	//			norms[i]=TrainMat->Norms[i];
	//		tree=new Tree(norms,n);
			timer->Stop();
			String ^str11=GlobalfName->Substring(GlobalfName->LastIndexOf("\\")+1);
			this->richTextBox2->AppendText(String::Concat("\n", str11,"\ttime Elapsed to build Normbased Multi BST \t", timer->ElapsedMilliseconds.ToString(),"\t"));

			label8->Text=String::Concat("Normbased Multi BST has been created : ","\t");
			//tree->TraversBreadth();//this print the tree on a text file DrawTree.txt*/


			
			//delete tree; tree=0;
			//print tree stats
				
		//	delete [] norms;


		 }
private: System::Void testNormBtreePerClassToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//this search for all examples in the test set in the created binary tree until 
	//reaching a leafe node 
			// TestMat->UpdateClasses();
			// TestMat->UpdateNorms(DistanceType);

			 float MaxV=-99999999999999999.0;
			for (long rr=0;rr<TrainMat->Row();rr++){
				float cl=TrainMat->classint[rr];
				if (cl > MaxV)
					MaxV=cl;
			}
			 float sum=0;
			 long *classinttwo=new long[TestMat->Row()];
			 long *classinttoo=new long[TestMat->Row()];
			 long * FN=new long[TestMat->NumberOfClasses()];
			 long * FP=new long[TestMat->NumberOfClasses()];
			 long * TN=new long[TestMat->NumberOfClasses()];
			 float * precision=new float[TestMat->NumberOfClasses()];
			 float * Recall=new float[TestMat->NumberOfClasses()];
             ArrayList^n=gcnew ArrayList();
		    long** classmat = new long*[TestMat->NumberOfClasses()];
            for(long i = 0; i < TestMat->NumberOfClasses(); ++i)
            classmat[i] = new long[TestMat->NumberOfClasses()];
			 for (long i=0;i<TestMat->Row();i++)
				{
					if ( ! n->Contains(TestMat->classint[i]))
						n->Add(TestMat->classint[i]);
			    }
				//classification	
				int k=Convert::ToInt32(this->textBox2->Text);
				this->progressBar1->Maximum=TestMat->Row();this->progressBar1->Value=0;
				Stopwatch ^timer = gcnew Stopwatch();  timer->Start();  
				for (long i=0;i<TestMat->Row();i++){
					//get the first test example 
					float *testRow=new float[TestMat->Col()];
					TestMat->getRow(testRow,i);
					//get the training indexes from the tree 
					BTreeNode * temp= new BTreeNode;//Multi01NormTree[0]->GetExamples(TestMat->Norms[i]);
					temp->size=0;
					for (long j=0;j<TreesNum;j++){
						BTreeNode * temp1=Multi01NormTree[j]->GetExamples(TestMat->Norms[i]);
						Add2BTNode(temp, temp1);
					}


					long cs=knnBtree(TrainMat,testRow,k,temp, MaxV);
					if (this->checkBox3->Checked)
						this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					classinttwo[i]=cs;
					classinttoo[i]=TestMat->classint[i];
					delete []testRow; testRow=0;
					this->progressBar1->Value++; Application::DoEvents();
				}
				//end classification
				timer->Stop();
			String ^str11=GlobalfName->Substring(GlobalfName->LastIndexOf("\\")+1);
				
				this->richTextBox2->AppendText(String::Concat("\n",str11,"\ttime Elapsed to test Norm based multi BST \t", timer->ElapsedMilliseconds.ToString(),"\n"));

				long index1=0;
				long index2=0;
				for (long i=0;i<TestMat->NumberOfClasses();i++)
					for (long j=0;j<TestMat->NumberOfClasses();j++)
						classmat[i][j]=0;

                //confusion matrix 
				for (long i=0;i<TestMat->Row();i++){
				    index1=n->IndexOf(classinttoo[i]);
					index2=n->IndexOf(classinttwo[i]);  
					if(classinttoo[i]== classinttwo[i])
						classmat[index1][index1]+=1;
					else
						classmat[index1][index2]+=1;

				}
                   
                delete []classinttoo;
                delete []classinttwo;


				int sumTP = 0;
            	for (int i=0;i<TestMat->NumberOfClasses();i++)
				{
					FN[i]=0;
					FP[i]=0;
					TN[i]=0;
					precision[i]=0.0;
					Recall[i]=0.0;
				}


            for (int i=0;i<TestMat->NumberOfClasses();i++)
					for (int j=0;j<TestMat->NumberOfClasses();j++)
						if(j!=i)
							FP[i]+=classmat[i][j];

			for (int i=0;i<TestMat->NumberOfClasses();i++)
					for (int j=0;j<TestMat->NumberOfClasses();j++)
						if(j!=i)
                  FN[i]+=classmat[j][i];

			 for (int i=0;i<TestMat->NumberOfClasses();i++)					
                 sumTP+=classmat[i][i];
             
			 for (int k=0;k<TestMat->NumberOfClasses();k++)
						
                  TN[k]=sumTP-classmat[k][k];

             for (int m=0;m<TestMat->NumberOfClasses();m++)
				if(	classmat[m][m]+ FP[m] == 0)
                    precision[m]=0.0;
				else
					precision[m]=classmat[m][m]/(float)(classmat[m][m]+FP[m]);

			 for (int v=0;v<TestMat->NumberOfClasses();v++)
				if(classmat[v][v]+FN[v] == 0)
                   Recall[v]=0.0;
				else
                   Recall[v]=classmat[v][v]/(float)(classmat[v][v]+FN[v]);
                
              float AvgPrecision = 0.0;
			  float SumPrecision = 0.0;
			  float SumRecall = 0.0;
              float AvgRecall = 0.0;
              for (int z=0;z<TestMat->NumberOfClasses();z++)
			  {
				  SumPrecision+=precision[z];
				  SumRecall+=Recall[z];
			  }


                delete []TN;
                delete []FN;
				delete []FP;
                delete [] Recall;
				delete [] precision;
				for(int i = 0; i < TestMat->NumberOfClasses(); ++i) {
                   delete [] classmat[i];
                }
                delete [] classmat;
           
            AvgRecall=SumRecall/(float)TestMat->NumberOfClasses();
            AvgPrecision=SumPrecision/(float)TestMat->NumberOfClasses();
			AvgRecall=Math::Round(AvgRecall,4.0);
			AvgPrecision=Math::Round(AvgPrecision,4.0);


			sum=sum/(float) TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat(" Norm tree Accuarcy\t",sum.ToString(),"\tRecall\t",AvgRecall.ToString(),"\tPrecision\t",AvgPrecision.ToString());
			this->richTextBox2->AppendText("k= " + this->textBox2->Text + label8->Text);

		 }
private: System::Void furthestPointDTToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
//this method train a binary search tree where each node store a number of training examples 
//based on their similarity to two local furthest points P1 and P2(diameter), 
//we used A2 algorithm (hill climbing) to find P1 and P2
//the closetes examples to P1 are stored to the left node
//the closetes points to P2 are stored to the right node 
//the examples are then clustered in a Bsearch tree 
//until they become one point, whch is stored in a leaf node.
//searching this tree is very fast (dlog n) 
//This BST is converted to a decsion tree by storing the parobability of each class in each node, 
//when testing and example these probabilities are consider to decide the class of the example without using KNN


			 //ensure that the norms are updated so to be used if p1 and p2 need swapp
			// TrainMat->UpdateNorms(DistanceType);
			 if (dt2furthestPts){
				 delete dt2furthestPts; dt2furthestPts=0;
			 }
			 int weigthmethod=Convert::ToInt16(this->textBox4->Text);
			//int k=Convert::ToInt32(this->textBox2->Text);
			long n=TrainMat->Row();
			Stopwatch ^timer = gcnew Stopwatch();  timer->Start(); 
			dt2furthestPts=new DT2FurthestPoints(TrainMat,DistanceType,weigthmethod);
			timer->Stop();
			String ^str11=GlobalfName->Substring(GlobalfName->LastIndexOf("\\")+1);
			this->richTextBox2->AppendText(String::Concat("\n", str11,"\tTime to build 2 Furthest points Decision Tree\t", timer->ElapsedMilliseconds.ToString(),"\t"));

			label8->Text=String::Concat("DT of 2 Furthest points is created : ","\t");
			if (this->checkBox3->Checked)
				dt2furthestPts->TraversBreadth();//this print the d tree on a text file DrawDTree.txt*/
			PrintStatDT2furthestPts(); 
	
		 }
private: System::Void testFurthesPointDTToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//this search for all examples in the test set in the created DT of 2 furthest points until 
	//reaching a leafe node to return, which may/may not contain one example,but contains the accumilated probabilities 
//for each class, the class with the highes AP wil be assigned to the test example.  

	if (!TestMat) {
		MessageBox::Show("no training set.....");
		return;

	}
		//	TestMat->UpdateNorms(DistanceType);
			 float MaxV=-99999999999999999.0;
			for (long rr=0;rr<TrainMat->Row();rr++){
				float cl=TrainMat->classint[rr];
				if (cl > MaxV)
					MaxV=cl;
			}
			 float sum=0;
			 long *classinttwo=new long[TestMat->Row()];
			 long *classinttoo=new long[TestMat->Row()];
			 long * FN=new long[TestMat->NumberOfClasses()];
			 long * FP=new long[TestMat->NumberOfClasses()];
			 long * TN=new long[TestMat->NumberOfClasses()];
			 float * precision=new float[TestMat->NumberOfClasses()];
			 float * Recall=new float[TestMat->NumberOfClasses()];
             ArrayList^n=gcnew ArrayList();
		    long** classmat = new long*[TestMat->NumberOfClasses()];
            for(long i = 0; i < TestMat->NumberOfClasses(); i++)
				classmat[i] = new long[TestMat->NumberOfClasses()];
			 for (long i=0;i<TestMat->Row();i++)
				{
					if ( ! n->Contains(TestMat->classint[i]))
						n->Add(TestMat->classint[i]);
			    }
//classification================================================================
				//int k=Convert::ToInt32(this->textBox2->Text);
				this->progressBar1->Maximum=TestMat->Row();this->progressBar1->Value=0;
				Stopwatch ^timer = gcnew Stopwatch();  timer->Start();  
				for (long i=0;i<TestMat->Row();i++){
					//get the first test example 
					//double *testRow=new double[TestMat->Col()];
					//TestMat->getRow(testRow,i);
					//search FPDT for the node that contains training examples with the best match to the test example and reveal the class of the highest AP   
					DTreeNode * temp=dt2furthestPts->GetExamples(TrainMat,TestMat, i,DistanceType);
					//long cs=knnBtree(TrainMat,testRow,k,temp, MaxV); old stuff
					
					//numclasses=dt2furthestPts->numclasses; 
					long cs=argmax(temp->Classint,dt2furthestPts->numclasses);
					if (this->checkBox3->Checked)
						this->richTextBox5->AppendText(String::Concat(cs.ToString(),"\n"));
					if (TestMat->classint[i]==cs)
						sum++;
					classinttwo[i]=cs;
					classinttoo[i]=TestMat->classint[i];
					//delete []testRow; testRow=0;
					this->progressBar1->Value++; Application::DoEvents();
				}
				timer->Stop();
//end classification=============================================================
			String ^str11=GlobalfName->Substring(GlobalfName->LastIndexOf("\\")+1);
				
				this->richTextBox2->AppendText(String::Concat("\n",str11,"\ttime for testing 2 Furthest Pts- Decision Tree",this->textBox4->Text,"\t", timer->ElapsedMilliseconds.ToString(),"\n"));

				long index1=0;
				long index2=0;
				for (long i=0;i<TestMat->NumberOfClasses();i++)
					for (long j=0;j<TestMat->NumberOfClasses();j++)
						classmat[i][j]=0;

                //confusion matrix 
				for (long i=0;i<TestMat->Row();i++){
				    index1=n->IndexOf(classinttoo[i]);
					index2=n->IndexOf(classinttwo[i]);  
					if(classinttoo[i]== classinttwo[i])
						classmat[index1][index1]+=1;
					else
						classmat[index1][index2]+=1;

				}
                   
                delete []classinttoo;
                delete []classinttwo;


				int sumTP = 0;
            	for (int i=0;i<TestMat->NumberOfClasses();i++)
				{
					FN[i]=0;
					FP[i]=0;
					TN[i]=0;
					precision[i]=0.0;
					Recall[i]=0.0;
				}


            for (int i=0;i<TestMat->NumberOfClasses();i++)
					for (int j=0;j<TestMat->NumberOfClasses();j++)
						if(j!=i)
							FP[i]+=classmat[i][j];

			for (int i=0;i<TestMat->NumberOfClasses();i++)
					for (int j=0;j<TestMat->NumberOfClasses();j++)
						if(j!=i)
                  FN[i]+=classmat[j][i];

			 for (int i=0;i<TestMat->NumberOfClasses();i++)					
                 sumTP+=classmat[i][i];
             
			 for (int k=0;k<TestMat->NumberOfClasses();k++)
						
                  TN[k]=sumTP-classmat[k][k];

             for (int m=0;m<TestMat->NumberOfClasses();m++)
				if(	classmat[m][m]+ FP[m] == 0)
                    precision[m]=0.0;
				else
					precision[m]=classmat[m][m]/(float)(classmat[m][m]+FP[m]);

			 for (int v=0;v<TestMat->NumberOfClasses();v++)
				if(classmat[v][v]+FN[v] == 0)
                   Recall[v]=0.0;
				else
                   Recall[v]=classmat[v][v]/(float)(classmat[v][v]+FN[v]);
                
              float AvgPrecision = 0.0;
			  float SumPrecision = 0.0;
			  float SumRecall = 0.0;
              float AvgRecall = 0.0;
              for (int z=0;z<TestMat->NumberOfClasses();z++)
			  {
				  SumPrecision+=precision[z];
				  SumRecall+=Recall[z];
			  }


                delete []TN;
                delete []FN;
				delete []FP;
                delete [] Recall;
				delete [] precision;
			//	for(int i = 0; i < TestMat->NumberOfClasses(); i++) {
            //       delete [] classmat[i];
           //     }
           //     delete classmat;
           
            AvgRecall=SumRecall/(float)TestMat->NumberOfClasses();
            AvgPrecision=SumPrecision/(float)TestMat->NumberOfClasses();
			AvgRecall=Math::Round(AvgRecall,4.0);
			AvgPrecision=Math::Round(AvgPrecision,4.0);


			sum=sum/(float) TestMat->Row();
			sum=Math::Round(sum,4.0);
			label8->Text=String::Concat(" 2 Furthest points DT accuracy=\t",sum.ToString(),"\tRecall\t",AvgRecall.ToString(),"\tPrecision:",AvgPrecision.ToString());
			this->richTextBox2->AppendText(label8->Text);

		 }
private: System::Void fixClassesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	
			 long row=TrainMat->Row(); 
			 long Minclass=TrainMat->classint[0];
			 for (long i=1;i<row;i++)
				 if (TrainMat->classint[i]<Minclass)
					 Minclass=TrainMat->classint[i];

			if (Minclass!=0)
				for (long i=0;i<row;i++)
					TrainMat->classint[i]=TrainMat->classint[i]-Minclass;
		 }
private: System::Void indextraindatUsing2FPBSTToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //this index all the features in atraining data into a BST using 2 furthest points BST
			 trainFurthestPBSTToolStripMenuItem_Click( sender,  e);

		 }
private: System::Void testIndexToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//this search for all examples in the test set in the created BST of 2 furthest points until 
	//reaching a leafe node to return, which may/may not contain one example
			// TestMat->UpdateNorms(DistanceType);
			 float MaxV=-99999999999999999.0;
			for (long rr=0;rr<TrainMat->Row();rr++){
				float cl=TrainMat->classint[rr];
				if (cl > MaxV)
					MaxV=cl;
			}
			 float sum=0;
//classification================================================================
				int k=Convert::ToInt32(this->textBox2->Text);
				int retexamples=Convert::ToInt32(this->textBox4->Text);

				int *output=new int [k];
				this->progressBar1->Maximum=TrainMat->Row();this->progressBar1->Value=0;
				Stopwatch ^timer = gcnew Stopwatch();  timer->Start();  
				for (long i=0;i<TrainMat->Row();i++){
					//get the first test example 
					float *testRow=new float[TrainMat->Col()];
					TrainMat->getRow(testRow,i);
					//get the training indexes from the BST of 2 extrm pnts tree 
					BTreeNode * temp=tree2furthestPts->GetExamples(TrainMat,TrainMat, i,DistanceType, retexamples);
					CBIRBtree(TrainMat,testRow,k,temp, MaxV, output);
					delete []testRow; testRow=0;
					this->richTextBox2->AppendText(String::Concat(TrainMat->classint[i].ToString(),"\t=>"));
					for (int j=0;j<k;j++){
						this->richTextBox2->AppendText(String::Concat("\t", output[j].ToString()));
					}
					this->richTextBox2->AppendText("\n");
					this->progressBar1->Value++; Application::DoEvents();
				}
				timer->Stop();
//end classification=============================================================
				delete []output; output=0;

		 }
private: System::Void randomMinMaxClassDTToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//this method train a binary search tree where each node store a number of training examples 
	//based on their similarity to two local points P1 and P2 belonging to the min and max class respectivly, 
	//the closetes examples to P1 are stored to the left node i.e min classe goes to left 
	//the closetes points to P2 are stored to the right node i.e examples of max class go to right 
	//the examples are then clustered in a Bsearch tree 
	//until they become one point in a leaf node, or a group of points with the same class in a leaf node too.
	//searching this tree is very fast (dlog n) 
	//This BST is converted to a decsion tree by storing the parobability of each class in each node, 
	//when testing and example these probabilities are consider to decide the class of the example without using KNN


				
	//TrainMat->UpdateNorms(DistanceType);
	if (dt2RandPMinMaxCls) {
		delete dt2RandPMinMaxCls; dt2RandPMinMaxCls = 0;
	}
	int weigthmethod = Convert::ToInt16(this->textBox4->Text);
	//int k=Convert::ToInt32(this->textBox2->Text);
	long n = TrainMat->Row();
	Stopwatch ^timer = gcnew Stopwatch();  timer->Start();
	dt2RandPMinMaxCls = new DTRandPMinMaxClass(TrainMat, DistanceType, weigthmethod);
	timer->Stop();
	String ^str11 = GlobalfName->Substring(GlobalfName->LastIndexOf("\\") + 1);
	this->richTextBox2->AppendText(String::Concat("\n", str11, "\tTime to build 2 Furthest points Decision Tree\t", timer->ElapsedMilliseconds.ToString(), "\t"));

	label8->Text = String::Concat("DT of 2 rand points belong to min max classes is created : ", "\t");
	if (this->checkBox3->Checked)
		dt2RandPMinMaxCls->TraversBreadth();//this print the d tree on a text file DrawDTree.txt*/
	Printdt2RandPMinMaxCls();


}
private: System::Void testRandomMinMaxClassDTToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//this search for all examples in the test set in the created DT of 2 furthest points until 
	//reaching a leafe node to return, which may/may not contain one example,but contains the accumilated probabilities 
//for each class, the class with the highes AP wil be assigned to the test example.  
	
	/*float MaxV = -99999999999999999.0;
	for (long rr = 0;rr < TrainMat->Row();rr++) {
		float cl = TrainMat->classint[rr];
		if (cl > MaxV)
			MaxV = cl;
	}*/

	float sum = 0;
	if (!TestMat) {
		MessageBox::Show("no training set.....");
		return;

	}
	//classification================================================================
					//int k=Convert::ToInt32(this->textBox2->Text);
	this->progressBar1->Maximum = TestMat->Row();this->progressBar1->Value = 0;
	Stopwatch ^timer = gcnew Stopwatch();  timer->Start();
	for (long i = 0;i < TestMat->Row();i++) {
		DTreeNode * temp = dt2RandPMinMaxCls->GetExamples(TrainMat, TestMat, i, DistanceType);
		//long cs=knnBtree(TrainMat,testRow,k,temp, MaxV); old stuff
		long cs = argmax(temp->Classint, dt2RandPMinMaxCls->numclasses);
		if (this->checkBox3->Checked)
			this->richTextBox5->AppendText(String::Concat(cs.ToString(), "\n"));
		if (TestMat->classint[i] == cs)
			sum++;
		
		this->progressBar1->Value++; Application::DoEvents();
	}
	timer->Stop();
	//end classification=============================================================
	String ^str11 = GlobalfName->Substring(GlobalfName->LastIndexOf("\\") + 1);

	this->richTextBox2->AppendText(String::Concat("\n", str11, "\ttime for testing 2 random min max class Pts- Decision Tree", this->textBox4->Text, "\t", timer->ElapsedMilliseconds.ToString(), "\n"));

	sum = sum / (float)TestMat->Row();
	sum = Math::Round(sum, 4.0);
	label8->Text = String::Concat("2 random min max class Pts DT accuracy=\t", sum.ToString());
	this->richTextBox2->AppendText(label8->Text);

}
private: System::Void zNormalizationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//Znormalize of train file
	TrainMat->ZNormalize();
}
private: System::Void kNNNfoldMultiRunsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//nfold multi runs 
	int mRuns = Convert::ToInt32(this->textBox4->Text);
	for (int j = 0; j < mRuns; j++) {
		Mat * AllDATA = TrainMat;
		long n = AllDATA->Row();
		long * Rndindxes = new long[n];
		int nfold = Convert::ToInt32(this->textBox5->Text);
		for (long i = 0;i < n;i++)
			Rndindxes[i] = i;
		for (long i = 0;i < n;i++) {
			long index = rnd->Next(0, n);
			//swap index by its location
			long temp = Rndindxes[index];
			Rndindxes[index] = Rndindxes[i];
			Rndindxes[i] = temp;
		}

		long stride = n / nfold;

		for (long i = 0, ii = 1; ii <= nfold; ii++, i += stride) {
			//initilize array of test indexes
			long * testIndexes = new long[stride];
			for (long j = 0; j < stride;j++)
				testIndexes[j] = Rndindxes[i + j];
			TrainTestMats ttm;
			//	ttm =ArrayListToMat(AllData,testIndexes,stride);//split data to train test 
			ttm = MatToMats(AllDATA, testIndexes, stride);//split data to train and test 
			delete[] testIndexes;testIndexes = 0;
			TrainMat = ttm.train;
			TestMat = ttm.test;
			//fold 
			this->richTextBox2->AppendText("\nFold...(" + ii.ToString() + ").............\n");

			//test knn
			kNNToolStripMenuItem_Click(sender, e);

			if (TrainMat) {
				delete TrainMat; TrainMat = 0;
			}
			if (TestMat) {
				delete TestMat; TestMat = 0;
			}
			Application::DoEvents();
		}

		delete[] Rndindxes;Rndindxes = 0;

		//return train mat as it is 
		if (TrainMat) {
			delete TrainMat; TrainMat = 0;
		}

		TrainMat = AllDATA;
	}
}


};
}