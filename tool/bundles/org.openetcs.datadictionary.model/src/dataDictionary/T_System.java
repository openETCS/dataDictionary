/**
 */
package dataDictionary;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import org.eclipse.emf.common.util.Enumerator;

/**
 * <!-- begin-user-doc -->
 * A representation of the literals of the enumeration '<em><b>TSystem</b></em>',
 * and utility methods for working with them.
 * <!-- end-user-doc -->
 * @see dataDictionary.DataDictionaryPackage#getT_System()
 * @model
 * @generated
 */
public enum T_System implements Enumerator {
	/**
	 * The '<em><b>Kernel</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #KERNEL_VALUE
	 * @generated
	 * @ordered
	 */
	KERNEL(1, "Kernel", "Kernel"),

	/**
	 * The '<em><b>DMI</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #DMI_VALUE
	 * @generated
	 * @ordered
	 */
	DMI(2, "DMI", "DMI"),

	/**
	 * The '<em><b>RBC</b></em>' literal object.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #RBC_VALUE
	 * @generated
	 * @ordered
	 */
	RBC(3, "RBC", "RBC");

	/**
	 * The '<em><b>Kernel</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>Kernel</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #KERNEL
	 * @model name="Kernel"
	 * @generated
	 * @ordered
	 */
	public static final int KERNEL_VALUE = 1;

	/**
	 * The '<em><b>DMI</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>DMI</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #DMI
	 * @model
	 * @generated
	 * @ordered
	 */
	public static final int DMI_VALUE = 2;

	/**
	 * The '<em><b>RBC</b></em>' literal value.
	 * <!-- begin-user-doc -->
	 * <p>
	 * If the meaning of '<em><b>RBC</b></em>' literal object isn't clear,
	 * there really should be more of a description here...
	 * </p>
	 * <!-- end-user-doc -->
	 * @see #RBC
	 * @model
	 * @generated
	 * @ordered
	 */
	public static final int RBC_VALUE = 3;

	/**
	 * An array of all the '<em><b>TSystem</b></em>' enumerators.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	private static final T_System[] VALUES_ARRAY =
		new T_System[] {
			KERNEL,
			DMI,
			RBC,
		};

	/**
	 * A public read-only list of all the '<em><b>TSystem</b></em>' enumerators.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static final List<T_System> VALUES = Collections.unmodifiableList(Arrays.asList(VALUES_ARRAY));

	/**
	 * Returns the '<em><b>TSystem</b></em>' literal with the specified literal value.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static T_System get(String literal) {
		for (int i = 0; i < VALUES_ARRAY.length; ++i) {
			T_System result = VALUES_ARRAY[i];
			if (result.toString().equals(literal)) {
				return result;
			}
		}
		return null;
	}

	/**
	 * Returns the '<em><b>TSystem</b></em>' literal with the specified name.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static T_System getByName(String name) {
		for (int i = 0; i < VALUES_ARRAY.length; ++i) {
			T_System result = VALUES_ARRAY[i];
			if (result.getName().equals(name)) {
				return result;
			}
		}
		return null;
	}

	/**
	 * Returns the '<em><b>TSystem</b></em>' literal with the specified integer value.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public static T_System get(int value) {
		switch (value) {
			case KERNEL_VALUE: return KERNEL;
			case DMI_VALUE: return DMI;
			case RBC_VALUE: return RBC;
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
	private T_System(int value, String name, String literal) {
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
	
} //T_System
