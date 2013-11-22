/**
 */
package dataDictionary;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import org.eclipse.emf.common.util.Enumerator;

/**
 * <!-- begin-user-doc -->
 * A representation of the literals of the enumeration '<em><b>TSource Document</b></em>',
 * and utility methods for working with them.
 * <!-- end-user-doc -->
 * @see dataDictionary.DataDictionaryPackage#getT_SourceDocument()
 * @model
 * @generated
 */
public enum T_SourceDocument implements Enumerator {
	/**
	 * The '<em><b>SRS</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #SRS_VALUE
	 * @generated
	 * @ordered
	 */
	SRS(1, "SRS", "SRS300"),

	/**
	 * The '<em><b>System Analysis</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #SYSTEM_ANALYSIS_VALUE
	 * @generated
	 * @ordered
	 */
	SYSTEM_ANALYSIS(2, "SystemAnalysis", "SystemAnalysis");

	/**
	 * The '<em><b>SRS</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>SRS</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #SRS
	 * @model literal="SRS300"
	 * @generated
	 * @ordered
	 */
	public static final int SRS_VALUE = 1;

	/**
	 * The '<em><b>System Analysis</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>System Analysis</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #SYSTEM_ANALYSIS
	 * @model name="SystemAnalysis"
	 * @generated
	 * @ordered
	 */
	public static final int SYSTEM_ANALYSIS_VALUE = 2;

	/**
	 * An array of all the '<em><b>TSource Document</b></em>' enumerators.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private static final T_SourceDocument[] VALUES_ARRAY =
		new T_SourceDocument[] {
			SRS,
			SYSTEM_ANALYSIS,
		};

	/**
	 * A public read-only list of all the '<em><b>TSource Document</b></em>' enumerators.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final List<T_SourceDocument> VALUES = Collections.unmodifiableList(Arrays.asList(VALUES_ARRAY));

	/**
	 * Returns the '<em><b>TSource Document</b></em>' literal with the specified literal value.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static T_SourceDocument get(String literal) {
		for (int i = 0; i < VALUES_ARRAY.length; ++i) {
			T_SourceDocument result = VALUES_ARRAY[i];
			if (result.toString().equals(literal)) {
				return result;
			}
		}
		return null;
	}

	/**
	 * Returns the '<em><b>TSource Document</b></em>' literal with the specified name.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static T_SourceDocument getByName(String name) {
		for (int i = 0; i < VALUES_ARRAY.length; ++i) {
			T_SourceDocument result = VALUES_ARRAY[i];
			if (result.getName().equals(name)) {
				return result;
			}
		}
		return null;
	}

	/**
	 * Returns the '<em><b>TSource Document</b></em>' literal with the specified integer value.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static T_SourceDocument get(int value) {
		switch (value) {
			case SRS_VALUE: return SRS;
			case SYSTEM_ANALYSIS_VALUE: return SYSTEM_ANALYSIS;
		}
		return null;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private final int value;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private final String name;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private final String literal;

	/**
	 * Only this class can construct instances.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private T_SourceDocument(int value, String name, String literal) {
		this.value = value;
		this.name = name;
		this.literal = literal;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public int getValue() {
	  return value;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String getName() {
	  return name;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String getLiteral() {
	  return literal;
	}

	/**
	 * Returns the literal value of the enumerator, which is its string representation.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public String toString() {
		return literal;
	}
	
} //T_SourceDocument
