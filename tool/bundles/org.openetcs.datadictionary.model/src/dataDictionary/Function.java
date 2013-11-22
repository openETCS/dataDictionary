/**
 */
package dataDictionary;

import org.eclipse.emf.common.util.EList;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Function</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * <ul>
 *   <li>{@link dataDictionary.Function#getName <em>Name</em>}</li>
 *   <li>{@link dataDictionary.Function#getSubFunction <em>Sub Function</em>}</li>
 *   <li>{@link dataDictionary.Function#getAllocation <em>Allocation</em>}</li>
 *   <li>{@link dataDictionary.Function#getInput <em>Input</em>}</li>
 *   <li>{@link dataDictionary.Function#getOutput <em>Output</em>}</li>
 *   <li>{@link dataDictionary.Function#getInternal <em>Internal</em>}</li>
 *   <li>{@link dataDictionary.Function#getRequirement <em>Requirement</em>}</li>
 *   <li>{@link dataDictionary.Function#isSafety <em>Safety</em>}</li>
 *   <li>{@link dataDictionary.Function#getDefinition <em>Definition</em>}</li>
 * </ul>
 * </p>
 *
 * @see dataDictionary.DataDictionaryPackage#getFunction()
 * @model
 * @generated
 */
public interface Function extends EObject {
	/**
	 * Returns the value of the '<em><b>Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Name</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Name</em>' attribute.
	 * @see #setName(String)
	 * @see dataDictionary.DataDictionaryPackage#getFunction_Name()
	 * @model required="true"
	 * @generated
	 */
	String getName();

	/**
	 * Sets the value of the '{@link dataDictionary.Function#getName <em>Name</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Name</em>' attribute.
	 * @see #getName()
	 * @generated
	 */
	void setName(String value);

	/**
	 * Returns the value of the '<em><b>Sub Function</b></em>' containment reference list.
	 * The list contents are of type {@link dataDictionary.Function}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Sub Function</em>' containment reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Sub Function</em>' containment reference list.
	 * @see dataDictionary.DataDictionaryPackage#getFunction_SubFunction()
	 * @model containment="true"
	 * @generated
	 */
	EList<Function> getSubFunction();

	/**
	 * Returns the value of the '<em><b>Allocation</b></em>' attribute.
	 * The literals are from the enumeration {@link dataDictionary.T_System}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Allocation</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Allocation</em>' attribute.
	 * @see dataDictionary.T_System
	 * @see #setAllocation(T_System)
	 * @see dataDictionary.DataDictionaryPackage#getFunction_Allocation()
	 * @model unique="false" required="true"
	 * @generated
	 */
	T_System getAllocation();

	/**
	 * Sets the value of the '{@link dataDictionary.Function#getAllocation <em>Allocation</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Allocation</em>' attribute.
	 * @see dataDictionary.T_System
	 * @see #getAllocation()
	 * @generated
	 */
	void setAllocation(T_System value);

	/**
	 * Returns the value of the '<em><b>Input</b></em>' reference list.
	 * The list contents are of type {@link dataDictionary.Variable}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Input</em>' reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Input</em>' reference list.
	 * @see dataDictionary.DataDictionaryPackage#getFunction_Input()
	 * @model
	 * @generated
	 */
	EList<Variable> getInput();

	/**
	 * Returns the value of the '<em><b>Output</b></em>' reference list.
	 * The list contents are of type {@link dataDictionary.Variable}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Output</em>' reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Output</em>' reference list.
	 * @see dataDictionary.DataDictionaryPackage#getFunction_Output()
	 * @model
	 * @generated
	 */
	EList<Variable> getOutput();

	/**
	 * Returns the value of the '<em><b>Internal</b></em>' containment reference list.
	 * The list contents are of type {@link dataDictionary.Variable}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Internal</em>' containment reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Internal</em>' containment reference list.
	 * @see dataDictionary.DataDictionaryPackage#getFunction_Internal()
	 * @model containment="true"
	 * @generated
	 */
	EList<Variable> getInternal();

	/**
	 * Returns the value of the '<em><b>Requirement</b></em>' reference list.
	 * The list contents are of type {@link dataDictionary.Requirement}.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Requirement</em>' reference list isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Requirement</em>' reference list.
	 * @see dataDictionary.DataDictionaryPackage#getFunction_Requirement()
	 * @model required="true"
	 * @generated
	 */
	EList<Requirement> getRequirement();

	/**
	 * Returns the value of the '<em><b>Safety</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Safety</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Safety</em>' attribute.
	 * @see #setSafety(boolean)
	 * @see dataDictionary.DataDictionaryPackage#getFunction_Safety()
	 * @model unique="false" required="true"
	 * @generated
	 */
	boolean isSafety();

	/**
	 * Sets the value of the '{@link dataDictionary.Function#isSafety <em>Safety</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Safety</em>' attribute.
	 * @see #isSafety()
	 * @generated
	 */
	void setSafety(boolean value);

	/**
	 * Returns the value of the '<em><b>Definition</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of the '<em>Definition</em>' attribute isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Definition</em>' attribute.
	 * @see #setDefinition(String)
	 * @see dataDictionary.DataDictionaryPackage#getFunction_Definition()
	 * @model unique="false" required="true"
	 * @generated
	 */
	String getDefinition();

	/**
	 * Sets the value of the '{@link dataDictionary.Function#getDefinition <em>Definition</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Definition</em>' attribute.
	 * @see #getDefinition()
	 * @generated
	 */
	void setDefinition(String value);

} // Function
